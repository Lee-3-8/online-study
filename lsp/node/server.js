const express = require('express'); //express 모듈 불러오기
const path = require('path');
const app = express(); //app객체로 서버일 처리

app.use(express.static(path.josin(__dirname,'templates')));
//dirname은 node.js 전역변수 : 현재 위치를 가리킴
//node.js 환경에서는 디렉토리 주소를 다룰때 항상 path모듈을 사용\
/*
const path = require('path');
path.join('example', 'children', 'file1.js'); // 'example/children/file1.js'
path.join('example', 'children', '..', 'file2.js'); // 'example/file2.js'
path.join('example', 'children', 'grandson', '..', '..', 'file3.js'); // 'example/file3.js'
*/
app.get('/',(req,res) => {
	res.sendFile(path.join(__dirname,'templates','main.html'));
});

app.get('/about',(req,res)=>{
	res.sendFile(path.join(__dirname,'templates','about.html'));
});

app.listen(8080,()=>{ //8080포트에서 요청대기
	console.log('Express App on port 8080!');
});