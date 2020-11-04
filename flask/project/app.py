import os
from flask import Flask
from flask import render_template
from models import db
from api_v1 import api as api_v1

app = Flask(__name__)
app.register_blueprint(api_v1,url_prefix='/api/v1') #앞에 계속 붙 어있는

@app.route('/register')
def register():
    return render_template('register.html')

@app.route('/login')
def login():
    return render_template('login.html')

@app.route('/')
def hello():
    return 'hello'

basedir = os.path.abspath(os.path.dirname(__file__)) #현재있는 파일의 디렉토리
dbfile = os.path.join(basedir,'db.sqlite') #현재디렉토리안에 sqlite 파일만듬

app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///' + dbfile #사용하는 sql,db에 따라 달라짐
app.config['SQLALCHEMY_COMMIT_ON_TEARDOWN'] = True # teardown은 사용자 요청의 전달완료를 commit을 하겠다는 뜻
#commit은 내가 변경한사항이 데이터베이스에 반영되게함
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
app.config['SECRET_KEY'] = 'qewoijoaisdjfddffffoi'

db.init_app(app)
db.app = app
db.create_all()

if __name__ == "__main__":
    app.run(host='127.0.0.1',port=5000,debug=True)