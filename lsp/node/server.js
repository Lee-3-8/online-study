const express = require('express'); //express 모듈 불러오기
const methodOverride =require('method-override');
const bodyParser = require('body-parser');
const path = require('path');
const { sequelize } = require('./models');

const app = express(); //app객체로 서버일 처리
app.set('port',process.env.PORT||8081);

sequelize.sync({ force: false })
  .then(() => {
    console.log('데이터베이스 연결 성공');
  })
  .catch((err) => {
    console.error(err);
  });


app.use(express.static(__dirname + '/public'));

app.use(methodOverride());
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended : true }));

const mainRouter = require('./route');//아까 export했던 router를 연결

app.use('/',mainRouter);

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