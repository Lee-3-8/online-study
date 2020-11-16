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

#세션 활성화
s = requests.Session()
r = s.get('https://www.naver.com/')

#수신 데이터
# print(r.text)

#수신 상태 코드
print('Status Code : {}'.format(r.status_code))


# 확인
print('OK? : {}'.format(r.ok)) # True 반환


# 세션 열면 닫아줘야함~(with 문도 있음 )
s.close()