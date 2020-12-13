# Express JS
## 1강
 - Express 시작하기
 - 상태코드
     + 1xx  조건부응답
     + 2xx  응답성공
     + 3xx 리다이렉션
     + 4xx 요청오류
     + 5xx 서버오류 
- node 구성할때 package 자동생성 npm init -y

## 2강
- nodemon
- node js의 자동 디버깅 툴!!
- npm install nodemon 
- package-json->script에 start으로 별도 코드를설정

##3강

-     "start" : "nodemon app.js" 스크립트 변경시 npx nodemon app.js 하면
        모듈이 없더라도 설치하고 실행됨 

##4강

- 라우팅
- 폴더구조를 구분해서 모듈화하여 사용 

## 5강

- nunjucks
- 탬플릿 폴더구조는 라우트 폴더 구조를 똑같이 따라가는게 편하다 

## 6강
	- 미들웨어
	- morgan 사용 -> 로깅해주는 미들웨어
	- 로그인이 되어있는지 확인할때 미들웨어를 활용많이한다
	function loginRequired(req,res,next){
	if(로그인이 x){
		res.redirect(로그인창으로)
	}
}

##7강
	- 정적파일
	- node js에서는 uploads 폴더에 정적파일을 올린다 
	- 미들웨어에서 
	app.use('/uploads' , express.static('uploads'));

##10강
	- 사용하지 않는 변수는 _로 처리가능하다

##막강
	- 폴더구조 
	- controllers/index 모든 폴더
	- controllers/admin/index.js (admin url + 미들웨어)
	- controllers/admin/admin.ctrl.js (컨트롤러 역할)