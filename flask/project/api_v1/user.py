from flask import jsonify
from flask import request
from models import Fcuser, db
from . import api

@api.route('/users', methods=['GET','POST']) #모든사용자 get
def users():
	if request.method == 'POST':
		userid = request.form.get('userid')
		username = request.form.get('username')
		password = request.form.get('password')
		re_password = request.form.get('re_password')

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
