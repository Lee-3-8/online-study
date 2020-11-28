##미들웨어
-	요청에 대한 응답 과정을 중간에 껴서 어떠한 동작을 해주는 프로그램

- 종류
	- Morgan : 프레임워크가 동작하면서 나오는 메시지들을 콘솔에 표시
	- Compression : 페이지를 압축해서 전송
	- Session : 세션사용
	- Body-parser : 폼에서 전송되는 POST 값
	- Method-override : REST API에서 PUT , DELETE 메소드 사용가능하게함
	- Cors : 크로스오리진 가능(다른도메인 간의 AJAX 요청)
	- Multer : 파일업로드 할때 많이씀

-	직접만들수도 있고, 라우팅전에만 넣으면됨 , request,response를 매개변수로 받아 조작할 수 있다.
-	마지막으로 next()를 하면 다음 미들웨어로 넘어감

##라우팅

- 와일드카드 사용 : app.get('/post/:id') 이렇게하면 :뒤에부분은 뭐가와도 실행됨 pram같음

##그룹화
-	라우팅부분을 export 모듈시스템을 이용해서 그룹화한다.
'''
app.use('/category',route1);
'''
카테고리 url의 모든라우팅을 그룹화