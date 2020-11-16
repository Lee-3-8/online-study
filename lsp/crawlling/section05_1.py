# section05-1
# beautifulsoup 사용 스크래핑 2

from bs4 import BeautifulSoup

html = """
	<html>
	<head>
		<title>
			The Dormouse's story
		</title>
	</head>
	<body>
		<h1>this is h1</h1>
		<h2>this is h2</h2>
		<p class="title"><b>The dormouse's stroy</b> </p>
		<p class="story"> 어아무말 마마아아아루아ㅏ
			<a href="http://example.com/elsie" class="sister" id="link1">elsie</a>
			<a href="http://example.com/lacie" class="sister" id="link2">lacie</a>
			<a data-io="link3" href = "http://example.com/little" class="brother" id="link3">Title</a>
		</p>
		<p class="story">story...</p>
	</body>
</html>
"""

#예제1 bs4 기초
soup = BeautifulSoup(html,'html.parser')

#타입확인
# print('soup', type(soup))
# print('prettify', soup.prettify())

#h1 태그 접근
h1 = soup.html.body.h1
# print('h1',h1)

#p 태그 접근 여러개 있으면 가장 첫번째를 가져옴
p1 = soup.html.body.p
# print('p1',p1)

#다음 태그
#p->공백->그다음 , next는 그닥 많이안쓰고 알아만 두자
p2 = p1.next_sibling.next_sibling
# print('p2',p2)

# #텍스트 출력
# print('h1 >>',h1.string)
# print('p1 >>',p1.string)

# #함수확인
# print(dir(p2))

#다음 엘리먼트 확인 / 잘사용안하고 string으로함
# print(p2.next_element) # print(list(p2.next_element)

for v in p2.next_element:
	pass
	# print(v)


# 예제2 (find, findall)

soup2 = BeautifulSoup(html, 'html.parser')

#a 태그 모두선택 / 보통은 태그명보단 클래스나 id 로 가져옴 or img도 가능
link1 = soup.find_all('a', limit=1) # 리미티옵션은 순서대로 상위 몇개만가져옴
# print('links' , link1)


###########중요#############
link2 = soup.find_all('a', class_= 'sister')
 # id = 'link2' 나 string = "title"  string = ["Elsie","Title"] 도 가능
# print(link2)

for t in link2:
	print(t)



























