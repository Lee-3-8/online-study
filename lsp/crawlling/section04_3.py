#section04-3
#requests
#requests 사용 스크랩핑 (3) rest api

# rest api : get,post,delete, put:update , replace(fetch : update , modify)
# url을 활용해서 자원의 상태 정보를 주고받는 모든것을 의미
# GET www.movies.com/movies -> 영회를 전부 조회
# GEt www.movies.com/movies/id - > 아이디인 영화를 조회
# Post www.movies.com/movies/ 영화 생성
# PUT www.movies.com/movies/ 영화를 수정
# DELETE www.movies.com/movies/ 영화를 삭제

import requests
# 세션 활성화
s = requests.Session()

# 예제1
r = s.get('https://api.github.com/events')

# 수신상태  체크
r.raise_for_status()

#출력
# print(r.text)


#예제2
#쿠키설정

jar = requests.cookies.RequestsCookieJar()

#쿠키 삽입

jar.set('name' , 'niceman' , domain="httpbin.org", path='/cookies')

# 요청

r = s.get('https://httpbin.org/cookies', cookies=jar)

#출력
# print(r.text)

# 예제 3
r = s.get("https://github.com",timeout=5)

#출력
# print(r.text)


#예제 4
r = s.post("https://httpbin.org/post",data={'id':'test77' , 'pw' : '111'}, cookies=jar)

#출력
# print(r.text)
# print(r.headers)

# 예제 5
# 요청
test_url = "https://httpbin.org/"

payload1 = {'id':'test7787' , 'pw' : '11111'}
payload2 = (('id','test77') , ('pw','111')) #튜플로도가능

r = s.post(test_url + "post", data = payload1)

#출력
# print(r.text)

#예제6 (PUT)
r = s.put(test_url + "put" , data=payload1)

#출력
# print(r.text)

#예제 7

r = s.delete(test_url + "delete" , data={'id' : 1})

#출력
print(r.text)