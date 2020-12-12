const express = require('express');
const nunjucks = require('nunjucks');

const admin = require('./routes/admin');

const app = express();
const port = 3000;

nunjucks.configure('template',{
	autoescape : true, //보안상 true로
	express : app
});

app.get('/',(req,res)=>{
	res.send('hello express1');
});

app.use('/admin' , admin);

app.listen(port , ()=>{
	console.log('Express listening on port',port);
});