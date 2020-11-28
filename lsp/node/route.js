const express = require('express');
const path = require('path');
const router = express.Router();//라우터 분리


router.get('/',(req,res)=>{
	res.sendFile(path.join(__dirname,'public','test.html'));
});

router.get('/user/:name', (req,res)=>{

})
// router.get('/about',(req,res)=>{
// 	res.sendFile(path.join(__dirname,'templates','about.html'));
// });

module.exports = router; //모듈로 만드는 부분