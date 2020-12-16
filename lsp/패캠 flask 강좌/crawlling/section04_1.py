"""
Requset 요청 정보 payload
세션 활성화 및 비활성화
쿠키 정보 전송
User- Agent 정보 전송
수신 상태 코드 확인

section 04_1
requests 모듈에 대해서배움 (1) -session

"""
import requests

# #세션 활성화
# s = requests.Session()
# r = s.get('https://www.naver.com/')

# #수신 데이터
# # print(r.text)

# #수신 상태 코드
# print('Status Code : {}'.format(r.status_code))


# # 확인
# print('OK? : {}'.format(r.ok)) # True 반환


# # 세션 열면 닫아줘야함~(with 문도 있음 )
# s.close()


s = requests.Session()

# 쿠키 return
r1 = s.get('https://httpbin.org/cookies', cookies = {'name' : 'kim1'})
print(r1.text)

# 쿠키 set -> 서버에 쿠키정보 저장

r2 = s.get('https://httpbin.org/cookies/set', cookies = {'name' : 'kim2'})
print(r2.text)

# User-Agent
url = "https://httpbin.org"
headers = {'user-agent': 'nice-man_1.0.0_win10_ram16_home_chrome'}

#Header 정보 전송
r3 = s.get(url,headers=headers) # 인자에 쿠키도 넣어서 보낼 수 있다.

s.close()

# 실무에서 with문을 사용 권장함 -> 파일 ,DB,HTTP , 가독성이좋고 실수도줄일 수 있다.
 with requests.Session() as s:
 	r = s.get('http://finance.daum.net')
 	print(r.text)
 	print(r.ok)




