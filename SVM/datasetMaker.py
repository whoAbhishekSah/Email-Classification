# fout = open('datasetSVM.txt', 'w')
# i=1
# for i in range(1, 2000):
# 	j="business/"+str(i)+".txt"
# 	with open(j) as f:
# 	    content = f.readlines()
# 	content = [x.strip() for x in content] 
# 	string=""
# 	#print content
# 	for x in content:
# 		string=string+x+" "

# 	fout.write("\nbusiness"+"\t"+string)  # python will convert \n to os.linesep
# 	print string
# i=1

# for i in range(1, 2000):
# 	j="education/"+str(i)+".txt"
# 	with open(j) as f:
# 	    content = f.readlines()
# 	content = [x.strip() for x in content] 
# 	string=""
# 	#print content
# 	for x in content:
# 		string=string+x+" "

# 	fout.write("\neducation"+"\t"+string)  # python will convert \n to os.linesep
# 	print string

# fout.close()

fout = open('datasetSVM2.txt', 'w')
i=1
for i in range(1, 700):
	j="business/"+str(i)+".txt"
	with open(j) as f:
	    content = f.readlines()
	content = [x.strip() for x in content] 
	string=""
	#print content
	for x in content:
		string=string+x+" "

	fout.write("\nbusiness"+"\t"+string)  # python will convert \n to os.linesep
	print string
i=1

for i in range(1, 700):
	j="education/"+str(i)+".txt"
	with open(j) as f:
	    content = f.readlines()
	content = [x.strip() for x in content] 
	string=""
	#print content
	for x in content:
		string=string+x+" "

	fout.write("\neducation"+"\t"+string)  # python will convert \n to os.linesep
	print string

for i in range(1, 700):
	j="entertainment/"+str(i)+".txt"
	with open(j) as f:
	    content = f.readlines()
	content = [x.strip() for x in content] 
	string=""
	#print content
	for x in content:
		string=string+x+" "

	fout.write("\nentertainment"+"\t"+string)  # python will convert \n to os.linesep
	print string

for i in range(1, 700):
	j="social/"+str(i)+".txt"
	with open(j) as f:
	    content = f.readlines()
	content = [x.strip() for x in content] 
	string=""
	#print content
	for x in content:
		string=string+x+" "

	fout.write("\nsocial"+"\t"+string)  # python will convert \n to os.linesep
	print string
for i in range(1, 700):
	j="sports/"+str(i)+".txt"
	with open(j) as f:
	    content = f.readlines()
	content = [x.strip() for x in content] 
	string=""
	#print content
	for x in content:
		string=string+x+" "

	fout.write("\nsports"+"\t"+string)  # python will convert \n to os.linesep
	print string
fout.close()