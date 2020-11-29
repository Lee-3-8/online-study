const express = require('express');
const path = require('path');
const router = express.Router();//라우터 분리
const Todo = require('./models')
/*
post로 todo 데이터를 받아온다
papago로 번역기돌린다
db에 저장한다
db에 저장한 데이터를 반환한다.
*/

router.get('/',(req,res)=>{
	res.sendFile(path.join(__dirname,'public','test.html'));
});

router.get('/data',(req,res)=>{
	//db에 저장한거 모두 반환
	res.sendFile(path.join(__dirname,'public','test.html'));
});

router.post('/data',async (req,res)=>{
	Todo.create({
		koText : req.body.text,
		enText : 'test',
	})
	// const data = {
	// 	koText : req.body.text,
	// 	enText : 'text',
	// 	time : now,
	// 	id : 12
	// };
	const findAll = await Todo.findAll({});
	const findOne = await Todo.findOne({});

	console.log(findAll , findone);

	res.json(data);
})


module.exports = router; //모듈로 만드는 부분