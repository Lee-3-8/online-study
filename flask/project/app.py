import os
from flask import Flask
from flask import render_template
from models import db

app = Flask(__name__)

@app.route('/register')
def register():
    return render_template('register.html')

@app.route('/')
def hello():
    return render_template('hello.html')

if __name__ == "__main__":
    basedir = os.path.abspath(os.path.dirname(__file__)) #현재있는 파일의 디렉토리
    dbfile = os.path.join(basedir,'db.sqlite') #현재디렉토리안에 sqlite 파일만듬

    app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///' + dbfile #사용하는 sql,db에 따라 달라짐
    app.config['SQLALCHEMY_COMMIT_ON_TEARDOWN'] = True # teardown은 사용자 요청의 전달완료를 commit을 하겠다는 뜻
    #commit은 내가 변경한사항이 데이터베이스에 반영되게함
    app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False

    db.init_app(app)
    db.app = app
    # db = SQLAlchemy(app)#db를 사용해서 데이터와 관련된 모든것을함
    db.create_all()
    app.run(host='127.0.0.1',port=5000,debug=True)