#include<iostream>
#include<map>
#include<fstream>
using namespace std;
int main()
	{
	map<string,int> bussiness;
	ifstream input;
	input.open("li&sp&tr.txt");
	string word;
	while(input>>word)
		{
		++bussiness[word];
		}
	input.close();
	ofstream myfile("li&sp&tr_wordlist.txt");
	for (map<std::string, int>::iterator it = bussiness.begin(); it !=bussiness.end(); ++it)
		{
		if(it->second>=3)
			myfile<<it->first<<" : "<<it->second<< endl;
		}	
	myfile.close();
	return 0;
	}
