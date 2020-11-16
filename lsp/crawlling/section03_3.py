#다음 주식 사이트 크롤링 분석
# section03-3
# 기본 스크랩핑 실습
# 다음 주식 정보 가져오기

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
res = req.urlopen(req.Request(url, headers = headers))