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

import requests as req
# 세션 활성화
s = req.Session()

# 예제1
r = s.get('https//api.github.com/events')

# 수신상태  체크
r.raise_for_status()

#출력
print(r.text)


#예제2
#쿠키설정

jar = requests.cookies.RequestsCookieJar()

#쿠키 삽입

jar.set('name' , 'niceman' , domain="httpbin.org", path='/c')