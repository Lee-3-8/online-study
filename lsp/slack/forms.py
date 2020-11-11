from models import Fcuser
from flask_wtf import FlaskForm
from wtforms import StringField , PasswordField
from wtforms.validators import DataRequired, EqualTo

class RegisterForm(FlaskForm):
	userid = StringField('userid', validators=[DataRequired()])
	password = StringField('password', validators=[DataRequired()])
	repassword = StringField('repassword', validators=[DataRequired()])