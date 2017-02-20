import urllib2
import io
from bs4 import BeautifulSoup
file_r=open("bussiness-web-test.txt",'r')
i=268
for line in file_r:
	i=i+1
	f_n=str(i) +".txt"
	url = line
	try:
		html = urllib2.urlopen(url).read()
	except urllib2.HTTPError, e:
		continue
	except urllib2.URLError, e:
        	continue
	except httplib.HTTPException, e:
		continue
	except Exception, e:
		continue			
	soup = BeautifulSoup(html,"lxml")
	# kill all script and style elements
	for script in soup(["script", "style"]):
	    script.extract()    # rip it out
	# get text
	text = soup.get_text()
	# break into lines and remove leading and trailing space on each
	lines = (line.strip() for line in text.splitlines())
	# break multi-headlines into a line each
	chunks = (phrase.strip() for line in lines for phrase in line.split("  "))
	# drop blank lines
	text = '\n'.join(chunk for chunk in chunks if chunk)
	BeautifulSoup(text,from_encoding="utf-8")
	file_w=open(f_n,'w')
	file_w.write(text.encode('utf8') + '\n')
	file_w.close()
	print(text)
file_r.close()
