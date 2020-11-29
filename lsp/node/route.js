const express = require('express');
const path = require('path');

const router = express.Router();//라우터 분리
const { Todo } = require('./models')
/*
post로 todo 데이터를 받아온다
papago로 번역기돌린다
db에 저장한다
db에 저장한 데이터를 반환한다.
*/

router.get('/',(req,res)=>{
	res.sendFile(path.join(__dirname,'public','test.html'));
});

router.get('/data',async (req,res)=>{
	//db에 저장한거 모두 반환
	const findAll = await Todo.findAll({});
	let result = [];
	for (let i of findAll){
		result.push(i.dataValues);
	}
	console.log(result)
	res.json(result);
});

router.post('/data',async (req,res)=>{
	try	{
		const ID = 'PL0Z6LP0ymYVn6fiE5GC';
		const PASSWORD = '4GgNzE_cer';
		const URL = 'https://openapi.naver.com/v1/papago/n2mt'
		const options = {
			url : URL,
			form:{
				source : 'ko',
				target : 'en',
				text : req.body.text
			},
			headers:{
				'X-Naver-Client-Id': ID,
				'X-Naver-Client-Secret': PASSWORD
			},

		}
		const request = require('request');
		const translateResult = await request.post(options);
		console.log(translateResult.body.enco);

		const result = await Todo.create({
			ko_text : req.body.text,
			en_text : 'test',
		})

		console.log(result.dataValues);

		res.json(result.dataValues);
	}catch(err){
		console.log(err);
	}
})


module.exports = router; //모듈로 만드는 부분