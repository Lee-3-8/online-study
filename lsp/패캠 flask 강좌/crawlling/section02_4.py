# 파이썬 크롤링 기초
#lxml 사용 기초 스크랩핑 (5)

import requests
from lxml.html import fromstring, tostring

def main():
	"""
	네이버 메인 뉴스 스탠드 스크랩핑 메인함수
	"""
	#세션 사용
	session = requests.Session()
	# 스크랩핑 대상 URL
	response = session.get("https://www.naver.com")
	# session.close() 세션 끊을수도있음

	#신문사 링크 리스트 획득
	urls = scrape_news_list_page(response)

	# 딕셔너리 확인
	# print(urls)

	#결과 출력
	# for url in urls:

	# 	#url 출력
	# 	print(url)
	# 	#파일 쓰기

def scrape_news_list_page(response):
	# URL 딕셔너리 선언
	urls = {}
	#태그 정보 문자열 저장
	root = fromstring(response.content)

	# '//' => 전체문서에서
	for a in root.xpath('//div[@class="popup_wrap"]/a[3]'):
		#구조확인
		print('dd')
		# print(tostring(a, pretty_print=True))
		name,url =extract_contents(a)
		urls[name] = url


	return urls

def extract_contents(dom):
	#링크 주소
	link = dom.get("href")

	# 신문사 명
	name = dom.xpath('./img')

# 스크랩핑 시작
if __name__ == "__main__":
	main()


#/li[@class="popup_wrap"]/a[@class="btn_popup"]