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

- 4강
	- mysql ->직접 서버에 안넣고 RDS를 세팅함
	- aws에서 서비스-> rds를 생성 , 보안탭에서 mysql열어주고 ,인스턴스의 보안그룹도 보안설정에 추가해준다
	- 워크밴치로 연결
	-db연결이 잘됬는지는 select 2 from dual 하면 dual이 그냥 계산용 더미 테이블이라함 다른 테이블과 계산용 조인도 할 수 있음 굳 

-5강
	- .env 파일 : database 명 비번 등등 의 정보가있음 

- 막강
	- nginx로 프록시 설정 