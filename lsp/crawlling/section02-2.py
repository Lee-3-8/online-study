# 파이썬 크롤링 기초
# urliopen 함수 기초 사용법

import urllib.request as req
from urllib.error import URLError, HTTPError

# urllib에서의 예외처리 , 오류 처리

# 다운로드 경로 및 파일명
path_list = ["G:/test2.jpg", "G:/index1.html"]

# 다운로드 리소스 url
target_url = [
    "https://yt3.ggpht.com/a/AATXAJwwiFLq7c5yd-aRj_MXx1bSLmZe-nXaXMvKRDHH=s900-c-k-c0x00ffffff-no-rj",
    "http://google.com",
]

for i, url in enumerate(target_url):
	# 예외 처리
	try:
		#웹 수신 정보 읽기
		response = req.urlopen(url)

		#수신 내용
		contents = response.read()

		print("___________________________________")

		#상태 정보 중간 출력
		print('Header Info-{} : {}'.format(i,response.info()))
		print('HTTP Status Code: {}'.format(response.getcode()))
		print()
		print("___________________________________")
		with open(path_list[i] , 'wb') as c:
			c.write(contents)

	except HTTPError as e:
		print("Download failed.")
		print("HTTPError Code : ", e.code)
	except URLError as e:
		print("Download failed.")
		print("URL Error Reason : ", e.reason)

	# 성공 했을때
	else:
		print()
		print("Download Succed.")
