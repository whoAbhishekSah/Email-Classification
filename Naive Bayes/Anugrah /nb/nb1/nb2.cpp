#include<iostream>
#include<map>
#include<fstream>
using namespace std;
int main()
	{
	map<string,int> bussiness;
	ifstream input;
	input.open("test_file_vector.txt");
	string word;
	while(input>>word)
		{
		++bussiness[word];
		}
	input.close();
	ofstream myfile("test_file_vector_wordlist.txt");
	for (map<std::string, int>::iterator it = bussiness.begin(); it !=bussiness.end(); ++it)
        	myfile<<it->first<<" : "<<it->second<< endl;
	myfile.close();
	return 0;
	}
