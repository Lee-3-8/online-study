"""

section 04_2
requests 모듈에 대해서배움 (2) - json

"""

import json
import requests

with requests.Session() as s:
    r = s.get("https://httpbin.org/stream/100", stream=True)  # 텍스트로 불러올땐 stream  true로
#수신 확인
    print(r.text)

# encoding 확인
print('Encoding : {}'.format(r.encoding))
if r.encoding is None:
	r.encoding	= 'UTF-8'

print('After Encoding: {}'.format(r.encoding))