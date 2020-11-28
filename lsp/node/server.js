
//사용할 미들웨어를 요청보내기전에 불러ㅏ오면된다.
// const compression = require('compression')
// const cors = require('cors')
const express = require('express'); //express 모듈 불러오기
const methodOverride =require('method-override');
const bodyParser = require('body-parser');

const path = require('path');
const app = express(); //app객체로 서버일 처리


app.use(methodOverride());
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended : true }));

app.use((req,res,next)=>{
//미들웨어를 만들 수 도있다. 라우팅부분 (app.get, app.post) 위에만 넣으면됨
	console.log('안녕!');
	next();
});


// app.use(express.static(path.join(__dirname,'templates')));
//dirname은 node.js 전역변수 : 현재 위치를 가리킴
//node.js 환경에서는 디렉토리 주소를 다룰때 항상 path모듈을 사용\
/*
const path = require('path');
path.join('example', 'children', 'file1.js'); // 'example/children/file1.js'
path.join('example', 'children', '..', 'file2.js'); // 'example/file2.js'
path.join('example', 'children', 'grandson', '..', '..', 'file3.js'); // 'example/file3.js'
*/


const route = require('./route.js');//아까 export했던 router를 연결
app.use('/',route);
app.use((req,res,next)=>{
	res.status(404).send('일치하는 주소가 없습니다.')
});
app.use((err,req,res,next)=>{
	console.error(err.stack);
	res.status(500).send('서버에러');
});

// app.listen(8080,...);

// app.get('/',(req,res) => {
// 	res.sendFile(path.join(__dirname,'templates','main.html'));
// });

// app.get('/about',(req,res)=>{
// 	res.sendFile(path.join(__dirname,'templates','about.html'));
// });

app.listen(8081,()=>{ //8080포트에서 요청대기
	console.log('Express App on port 8081!');
});