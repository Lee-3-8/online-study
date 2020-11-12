# 파이썬 크롤링 기초
# urllib 사용법
import urllib.request as req


# 파일 url
img_url = "https://t1.daumcdn.net/thumb/R720x0/?fname=http://t1.daumcdn.net/brunch/service/user/4arX/image/ThmomYfV2fLl1k3iXCe__ZywsAk.jpg"
html_url = "http://google.com"

save_path1 = "G:/test1.jpg"
save_path2 = "G:/index.html"

try:
    file1, header1 = req.urlretrieve(img_url, save_path1)
    file2, header2 = req.urlretrieve(html_url, save_path2)
except Exception as e:
    print("Download failed")
    print(e)
else:
    # Header 정보 출력
    print(header1)
    print(header2)
