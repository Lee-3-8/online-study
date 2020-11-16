#다음 주식 사이트 크롤링 분석
# section03-3
# 기본 스크랩핑 실습
# 다음 주식 정보 가져오기

"""

스크랩핑에서는 사이트 분석이 중요하다.
다음 같은 큰 사이트들은 url로 직접 스크래핑이 안되기 때문에
아래와같이 header에 뭐가 필요한지 분석해서 (크롬 개발자도구로)
스크래핑할것

"""

import json
import urllib.request as req
from fake_useragent import UserAgent

# Fake Header정보 ( 가상으로 User-agent 생성 )
ua = UserAgent()
# print(ua.ie)
# print(ua.msie)
# print(ua.chrome)
# print(ua.safari)
# print(ua.random)

#헤더 정보
headers = {
		'User-agent' : ua.chrome,
		'referer' : 'http://finance.daum.net/'
}

#다음 주식 요청 URL
url =  "http://finance.daum.net/api/search/ranks?limit=10"

#요청
res = req.urlopen(req.Request(url, headers = headers)).read().decode('UTF-8')

# 응답 데이터 확인 JSon
# print('res',res)

# 응답 데이터 str -> json 변환 및 data 값 출력
rank_json = json.loads(res)['data']

#중간확인
# print('중간 확인  : ',rank_json,'\n')

for elm in rank_json:
	print('순위 : {}, 금액 : {}, 회사명 : {}'
		.format(elm.get('rank'), elm.get('tradePrice'), elm.get('name')))
	# 파일 , db에 저장하기
