const express = require('express');
const path = require('path');
const router = express.Router();//라우터 분리

/*
post로 todo 데이터를 받아온다
papago로 번역기돌린다
db에 저장한다
db에 저장한 데이터를 반환한다.
*/

router.get('/',(req,res)=>{
	res.sendFile(path.join(__dirname,'public','test.html'));
});


router.post('/data',(req,res)=>{
	const data = req.body;
	console.log(data);
	res.json(data);
})


module.exports = router; //모듈로 만드는 부분