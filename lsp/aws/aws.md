## AWS
 - 1강
 	- AWS에서 계정 생성
 	- micro 로 프리티어 서비스 받으면서 생성
 	- 보안 그룹 태그 추가 -> 원하는 ip만 받을 수 있음 
 	- aws 서버구성 , ssh키 .pem으로 저장 
- 2강
	- putty를 이용하여 윈도우에서 서버로 접근 
	- puttyzen으로 서버의 .pem 파일 (ssh)키를 .ppk파일로 바꾼다
	- putty를 이용하여 서버의 퍼블릭 ipv4 dns 주소로 접속한다
	 	(서버가 재동작되면 값이 바뀐다) 
- 3강
	- node js 설치
	- ubuntu에서 ls 현재 폴더구조 , pwd 현제폴더위치 
	- mkdir 폴더만들기
	- ls -al 하면 숨김권한까지 볼수 있다.
	- vi 파일이름 // 으로 파일 수정 할수잇고 esc + :wq로 저장하고나가기 , :q로 나가기가능
	-pm2 모듈 : 계속 떠있게하는거 
	- pm2 start bin/www 로 시작 , pm2 list로 실행중인것도 볼수 잇음
	- pm2 stop 번호 로 멈출 수 있음
		
