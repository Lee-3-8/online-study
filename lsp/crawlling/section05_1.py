# section05-1
# beautifulsoup 사용 스크래핑 1

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
			<a data-io="link3" href = "http://example.com/little" class="sister" id="link3">Title</a>
		</p>
		<p class="story">story...</p>
	</body>
</html>
"""

