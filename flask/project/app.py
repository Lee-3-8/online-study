import os
from flask import Flask
from flask import request
from flask import redirect
from flask import render_template
from models import db
from flask_wtf.csrf import CSRFProtect
from forms import RegisterForm

from models import Fcuser

app = Flask(__name__)

@app.route('/login', methods = ['GET','POST'])
def login():
    if request.method == 'POST':
        userid = request.form.get(userid)
    return render_template('login.html')


@app.route('/register', methods = ['GET','POST'])
def register():
    form = RegisterForm()
    if request.method == 'POST':
        userid = request.form.get('userid')
        username = request.form.get('username')
        password = request.form.get('password')
        re_password = request.form.get('re-password')

        if (userid and username and password and re_password) and password == re_password:
            fcuser = Fcuser() #인스턴스 생성
            fcuser.userid = userid
            fcuser.username = username
            fcuser.password = password

            db.session.add(fcuser) #db에 넣는 부분
            db.session.commit() #자동으로 하게 설정해놧지만 습관들이자

            return redirect('/')
    return render_template('register.html',form=form)


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
    app.config['SECRET_KEY'] = 'qewoijoaisdjfoi'

    csrf = CSRFProtect()
    csrf.init_app(app)
    db.init_app(app)
    db.app = app
    # db = SQLAlchemy(app)#db를 사용해서 데이터와 관련된 모든것을함
    db.create_all()
    app.run(host='127.0.0.1',port=5000,debug=True)