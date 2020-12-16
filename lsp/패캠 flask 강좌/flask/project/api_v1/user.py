from flask import jsonify
from flask import request
from flask_jwt import jwt_required
from urllib.request import urlopen
from bs4 import BeautifulSoup
from models import Fcuser, db

from . import api

@api.route('/users', methods=['GET','POST']) #모든사용자 get
@jwt_required
def users():
	if request.method == 'POST':
		data =request.get_json()

		userid =  data.get('userid')
		username =  data.get('username')
		password =  data.get('password')
		re_password =  data.get('re_password')

		if not (userid and username and password and re_password):
			return jsonify({'error' : 'No arguments'}), 400

		if password != re_password:
			return jsonify({'error' : 'Wrong password'}), 400

		fcuser = Fcuser()
		fcuser.userid = userid
		fcuser.username = username
		fcuser.password = password

		db.session.add(fcuser)
		db.session.commit()

		return jsonify(), 201

	users = Fcuser.query.all()
	return jsonify([user.serialize for user in users])

@api.route('/users/<uid>', methods = ['GET','POST','DELETE'])#<>괄호로 id받을수잇음
def user_detail(uid):
	if request.method == 'GET':
		user = Fcuser.query.filter(Fcuser.id == uid).first()
		return jsonify(user.serialize)
	elif request.method == 'DELETE':
		user = Fcuser.query.delete(Fcuser.id == uid)
		return jsonify(),204 #앞으로 이컨텐츠는 이용 불가

	data = request.get_json()

	userid = data.get('userid')
	username = data.get('username')
	password = data.get('password')

	updated_data = {}
	if userid:
		updated_data['userid'] = userid
	if username:
		updated_data['username'] = username
	if password:
		updated_data['password'] = password

	Fcuser.query.filter(Fcuser.id == uid).update(updated_data)
	user = Fcuser.query.filter(Fcuser.id == uid).first()
	return jsonify(user.serialize)

@api.route('/crawler', methods=['GET'])
def crawler():
	input_num = '260'
	category = '2002'
	f = open("G:/도서목록260.txt",'w')
	for i in range(10000,10003):
		index = str(i)
		print("     "+ index)
		html = urlopen("https://lod.nl.go.kr/home/test/timeLine/marc.jsp?uri=http://lod.nl.go.kr/resource/KMO"+category+index+"&table_name=marc")
		bsObject = BeautifulSoup(html, "html.parser")
		flag = False
		for link in bsObject.find_all('tr'):
			a = str(link.find('td'))
			b = a[4:7]
			if(b == '001'):
				c = str(link.select(".left"))[18:30]
			if(b == input_num):
				flag = True
		if(flag == True):
			f.write(c+"\n")
			print(c)
	f.close()
	return jsonify({})

