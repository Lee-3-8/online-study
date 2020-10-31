from flask_sqlalchemy import SQLAlchemy
 
db = SQLAlchemy()

class Fcuser(db.Model):
    __tablename__ = 'fcuser'
    id = db.Column(db.Integer,primary_key=True)#순차적으로 증가하는 
    password = db.Column(db.String(32))
    username = db.Column(db.String(8))
