from flask import jsonify
from flask import request
from flask import Blueprint
from models import Todo,db
import requests
from . import api


@api.route("/todos", methods=["Get", "POST"])
def todos():
	if request.method == "POST":
		res = requests.post(
			"https://hooks.slack.com/services/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",
			json={"text": "Hello world"},
			headers={"Content-Type": "application/json"},
		)
	elif request.method == "GET":
		pass

	data = request.get_json()
	return jsonify(data)


@api.route("/slack/todos", methods=["POST"])
def slack_todos():

	res = request.form["text"].split(' ')
	cmd, *args = res

	ret_msg = ''

	if cmd == 'create':
		todo_name = args[0]

		todo = Todo()
		todo.title = todo_name

		db.session.add(todo)
		db.session.commit()
		ret_msg = 'todo가 생성되었습니다.'

	elif cmd == 'list':
		todos = Todo.query.all()
		for idx, todo in enumerate(todos):
			ret_msg += '%d. %s (~%s)\n'%(idx+1, todo.title, str(todo.tstamp))

	return jsonify(ret_msg)
