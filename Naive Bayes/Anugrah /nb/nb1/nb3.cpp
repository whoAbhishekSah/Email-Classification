#include<iostream>
#include<map>
#include<fstream>
#include<math.h>
#include<vector>
using namespace std;
map<string,int> bussiness;
map<string,int> education;
map<string,int> entertainment;
map<string,int> travel;
map<string,int> sports;
map<string,int> literature;
map<string,int> social;
vector<string> test;
long long pBussiness=1;
long long pSocial=1;
void make_bussiness()
	{
	ifstream file;
	file.open("data_set/buss_wordlist.txt");
	string str;
	string word;
	int freq;
	while(file>>str)
		{
		word=str;
		file>>str;
		file>>freq;
		bussiness[word]=freq;
		}
	}
void make_education()
	{
	ifstream file;
	file.open("data_set/educ_wordlist.txt");
	string str;
	string word;
	int freq;
	while(file>>str)
		{
		word=str;
		file>>str;
		file>>freq;
		education[word]=freq;
		}
	}
void make_entertainment()
	{
	ifstream file;
	file.open("data_set/entertain_wordlist.txt");
	string str;
	string word;
	int freq;
	while(file>>str)
		{
		word=str;
		file>>str;
		file>>freq;
		entertainment[word]=freq;
		}
	}
void make_travel()
	{
	ifstream file;
	file.open("data_set/travel_wordlist.txt");
	string str;
	string word;
	int freq;
	while(file>>str)
		{
		word=str;
		file>>str;
		file>>freq;
		travel[word]=freq;
		}
	}
void make_sports()
	{
	ifstream file;
	file.open("data_set/sports_wordlist.txt");
	string str;
	string word;
	int freq;
	while(file>>str)
		{
		word=str;
		file>>str;
		file>>freq;
		sports[word]=freq;
		}
	}
void make_literature()
	{
	ifstream file;
	file.open("data_set/literature_wordlist.txt");
	string str;
	string word;
	int freq;
	while(file>>str)
		{
		word=str;
		file>>str;
		file>>freq;
		literature[word]=freq;
		}
	}
void make_social()
	{
	ifstream file;
	file.open("data_set/social_wordlist.txt");
	string str;
	string word;
	int freq;
	while(file>>str)
		{
		word=str;
		file>>str;
		file>>freq;
		social[word]=freq;
		}
	}
void make_test()
	{
	ifstream file;
	file.open("test_file_vector.txt");
	string str;
	while(file>>str)
		{
		test.push_back(str);
		}
	}
void find_p()
	{
	for(int i=0;i<test.size();i++)
		{
		string word=test[i];
		//cout<<"word :"<<word<<endl;
		//cout<<(pBussiness*val_bussiness)%100000007<<" = "<<pBussiness<<"  *  "<<val_bussiness<<endl;
		pBussiness=(pBussiness*(bussiness[word]+1))%100000007;
		//cout<<(pSocial*val_social)%100000007<<" = "<<pSocial<<"  *  "<<val_social<<endl;		
		pSocial=(pSocial*(social[word]+1))%100000007;		
		}
	}
int main()
	{
	//cout<<pBussiness<<endl;
	make_bussiness();
	make_education();
	make_entertainment();
	make_social();
	make_travel();
	make_literature();
	make_sports();
	/*cout<<bussiness.size()<<endl;
	cout<<education.size()<<endl;
	cout<<literature.size()<<endl;
	cout<<travel.size()<<endl;
	cout<<sports.size()<<endl;
	cout<<entertainment.size()<<endl;
	cout<<social.size()<<endl;*/
	/**************************** read input file and output a text file full of stemmed words with freq ****************/
	make_test();
	cout<<test.size()<<endl;
	for(int i=0;i<test.size();i++)
		{
		cout<<test[i]<<endl;
		}
	find_p();
	cout<<"Probabilty of social "<<pSocial<<endl;
	cout<<"Probablity of Bussiness "<<pBussiness<<endl;
	if (pSocial>pBussiness)
		cout<<"It's SOCIAL"<<endl;
	else
		cout<<"It's BUSSINESS"<<endl;
	return 0;
	}
