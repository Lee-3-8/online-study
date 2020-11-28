const express = require('express'); //express 모듈 불러오기
const methodOverride =require('method-override');
const bodyParser = require('body-parser');
const path = require('path');

const app = express(); //app객체로 서버일 처리

app.use(express.static(__dirname + '/public'));

app.use(methodOverride());
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended : true }));

const route = require('./route.js');//아까 export했던 router를 연결
app.use('/',route);
app.use((req,res,next)=>{
	res.status(404).send('일치하는 주소가 없습니다.')
});
app.use((err,req,res,next)=>{
	console.error(err.stack);
	res.status(500).send('서버에러');
});

app.listen(8081,()=>{ //8080포트에서 요청대기
	console.log('Express App on port 8081!');
});