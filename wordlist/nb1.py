import nltk
import re
import string
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize
from nltk.stem.porter import PorterStemmer
import os.path
f_new=open("test_file",'w')
file_name="test.txt"
if os.path.isfile(file_name):
	print file_name	
	f=open(file_name)
	raw=f.read()
	raw=raw.decode("utf8")
	tokenized_raw=[word_tokenize(raw)]
	regex = re.compile('[%s]' % re.escape(string.punctuation)) #see documentation here: http://docs.python.org/2/library/string.html
	tokenized_raw_no_punctuation = []
	for review in tokenized_raw:
	    new_review = []
	    for token in review: 
		new_token = regex.sub(u'', token)
		if not new_token == u'':
		    new_review.append(new_token)
	    tokenized_raw_no_punctuation.append(new_review)
	tokenized_raw_no_stopwords = []
	for doc in tokenized_raw_no_punctuation:
	    new_term_vector = []
	    for word in doc:
		if not word in stopwords.words('english'):
		    new_term_vector.append(word)
	    tokenized_raw_no_stopwords.append(new_term_vector)
	#print tokenized_raw_no_stopwords
	#print tokenized_raw_no_punctuation
	#from nltk.stem.snowball import SnowballStemmer
	#from nltk.stem.wordnet import WordNetLemmatizer
	porter = PorterStemmer()
	#snowball = SnowballStemmer('english')
	#wordnet = WordNetLemmatizer()
	preprocessed_docs = []
	for doc in tokenized_raw_no_stopwords:
	    final_doc = []
	    for word in doc:
		final_doc.append(porter.stem(word))
		#final_doc.append(snowball.stem(word))
		#final_doc.append(wordnet.lemmatize(word)) #note that lemmatize() can also takes part of speech as an argument!
	    preprocessed_docs.append(final_doc)
	f.close()
	nl=nltk.pos_tag(preprocessed_docs[0])
	#print nl
	list=[]
	invalidChars = set(string.punctuation)
	for ele in preprocessed_docs[0]: 
		String=ele.encode("utf-8")
		#type(string)	
		if len(String)>2 and len(String)<10 and bool(re.search(r'\d', String))==False and re.match("^[a-zA-Z0-9_]*$", String):	 
			f_new.write("%s\n" % String)
	#print nl
	#for ele in list:
	#	print ele
	
f_new.close()










