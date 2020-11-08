from flask import jsonify
from flask import request
from flask import Blueprint
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


@api.route("/test", methods=["POST"])
def test():
    res = request.form["text"]
    print(res)

    return jsonify(res)
