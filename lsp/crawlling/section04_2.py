"""

section 04_2
requests 모듈에 대해서배움 (2) - json

"""

import json
import requests

s = requests.Session()

# r = s.get("https://httpbin.org/stream/100", stream=True)  # 텍스트로 불러올땐 stream  true로
# # 수신 확인
# print(r.text)
# # encoding 확인
# print('Encoding : {}'.format(r.encoding))
# if r.encoding is None:
# 	r.encoding	= 'UTF-8'
# print('After Encoding: {}'.format(r.encoding))
# for line in r.iter_lines(decode_unicode=True):
# 	# 라인 출력 후 타입 확인
# 	# print(line)
# 	# print(type(line))
# 	#json(Dict) 변환 후 타입 확인
# 	b = json.loads(line)
# 	print(b)
# 	print(type(b))
# 	# 정보 내용 출력
# 	for k,v in b.items():
# 		print("Key: {} , Value : {}".format(k,v))

r = s.get("https://jsonplaceholder.typicode.com/todos/1")

print(r.headers)
print(r.text)
print(r.json().keys())
print(r.json().values())
print(r.encoding)
# 바이너리 정보
print(r.content)

s.close()