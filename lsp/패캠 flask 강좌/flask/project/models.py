from flask_sqlalchemy import SQLAlchemy

db = SQLAlchemy()

class Fcuser(db.Model):
    __tablename__ = 'fcuser'
    id = db.Column(db.Integer,primary_key=True)#순차적으로 증가하는
    password = db.Column(db.String(64))
    userid = db.Column(db.String(32))
    username = db.Column(db.String(8))

    @property
    def serialize(self):
    	return {
    		'id' : self.id,
    		'password' : self.password,
    		'userid' : self.userid,
    		'username' : self.username
    	}
