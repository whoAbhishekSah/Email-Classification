string=""
fout = open('1.txt', 'w')
with open("test_file_vector.txt") as f:
	content = f.readlines()
	content = [x.strip() for x in content] 
	#print content
	for x in content:
		string=string+x+" "
print string
fout.write(string)  # python will convert \n to os.lines