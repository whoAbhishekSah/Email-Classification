#include<iostream>
#include<map>
#include<fstream>
#include<math.h>
#include<vector>
#include<sstream>
#include "bigint.cpp"
using namespace std;
map<string,int> bussiness;
map<string,int> education;
map<string,int> entertainment;
map<string,int> li_sp_tr;
map<string,int> social;
vector<string> test;
string pBussiness="1";
string pSocial="1";
string pEntertainment="1";
string pEducation="1";
string pLi_sp_tr="1";
void make_bussiness()
	{
	ifstream file;
	file.open("new_data_set/bussiness_wordlist.txt");
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
	file.open("new_data_set/education_wordlist.txt");
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
	file.open("new_data_set/entertainment_wordlist.txt");
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
void make_li_sp_tr()
	{
	ifstream file;
	file.open("new_data_set/li&sp&tr_wordlist.txt");
	string str;
	string word;
	int freq;
	while(file>>str)
		{
		word=str;
		file>>str;
		file>>freq;
		li_sp_tr[word]=freq;
		}
	}

void make_social()
	{
	ifstream file;
	file.open("new_data_set/social_wordlist.txt");
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
bool check_in(string category,string word)
	{	
	map<string,int>::iterator it;
	if(category=="bussiness")
		{
		it=bussiness.find(word);
		if (it==bussiness.end()) 
			return false;
		else
			return true;
		}
	if(category=="education")
		{
		it=education.find(word);
		if (it==education.end()) 
			return false;
		else
			return true;
		}
	if(category=="entertainment")
		{
		it=entertainment.find(word);
		if (it==entertainment.end()) 
			return false;
		else
			return true;
		
		}
	if(category=="social")
		{
		it=social.find(word);
		if (it==social.end()) 
			return false;
		else
			return true;
		
		}
	if(category=="li_sp_tr")
		{
		it=li_sp_tr.find(word);
		if (it==li_sp_tr.end()) 
			return false;
		else
			return true;
		
		}
	}
void find_p()
	{
	BigInteger obj;
	for(int i=0;i<test.size();i++)
		{
		/**bussiness**/
		string word=test[i];
		if(check_in("bussiness",word)==true)
			{
			ostringstream s1;
			s1<<bussiness[word];
			string a=s1.str();
			//cout<<"adding "<<a<<" and 1 to get "<<obj.add(a,"1")<<endl;		
			a=obj.add(a,"1");
			pBussiness=obj.multiply(a,pBussiness);
			}
		/**social**/
		if(check_in("social",word)==true)
			{			
			ostringstream s2;
			s2<<social[word];
			string b=s2.str();		
			//cout<<"adding "<<b<<" and 1 to get "<<obj.add(b,"1")<<endl;
			b=obj.add(b,"1");
			pSocial=obj.multiply(b,pSocial);		
			}
		/**education**/
		if(check_in("education",word)==true)
			{
			ostringstream s3;
			s3<<education[word];
			string c=s3.str();
			//cout<<"adding "<<c<<" and 1 to get "<<obj.add(c,"1")<<endl;		
			c=obj.add(c,"1");
			pEducation=obj.multiply(c,pEducation);						
			}
		/**entertainment**/
		if(check_in("entertainment",word)==true)
			{		
			ostringstream s4;
			s4<<entertainment[word];
			string d=s4.str();
			//cout<<"adding "<<d<<" and 1 to get "<<obj.add(d,"1")<<endl;		
			d=obj.add(d,"1");
			pEntertainment=obj.multiply(d,pEntertainment);
			}
		/**li&sp&tr**/
		if(check_in("li_sp_tr",word)==true)
			{
			ostringstream s5;
			s5<<li_sp_tr[word];
			string e=s5.str();
			//cout<<"adding "<<e<<" and 1 to get "<<obj.add(e,"1")<<endl;		
			e=obj.add(e,"1");
			pLi_sp_tr=obj.multiply(e,pLi_sp_tr);
			}
		}
	}
string maxx(string a,string b)
	{
	BigInteger obj;
	if (obj.greater(a,b)==true)
		return a;
	else
		return b;	
	}
int main()
	{
	make_bussiness();
	make_education();
	make_entertainment();
	make_social();
	make_li_sp_tr();
	make_test();
	cout<<test.size()<<endl;
	find_p();
	/* output result */
	cout<<"BUSSINESS : "<<pBussiness<<endl;
	cout<<"EDUCATION : "<<pEducation<<endl;
	cout<<"ENTERTAINMENT : "<<pEntertainment<<endl;
	cout<<"SOCIAL : "<<pSocial<<endl;
	cout<<"LI & TR & SP : "<<pLi_sp_tr<<endl;
	string ans=maxx(maxx(maxx(maxx(pBussiness,pEducation),pEntertainment),pSocial),pLi_sp_tr);
	if(ans==pBussiness)
		cout<<"ITS BUSSINESS"<<endl;
	if(ans==pSocial)
		cout<<"ITS SOCIAL"<<endl;
	if(ans==pEducation)
		cout<<"ITS EDUCATION"<<endl;
	if(ans==pEntertainment)
		cout<<"ITS ENTERTAINMENT"<<endl;
	if(ans==pLi_sp_tr)
		cout<<"ITS Li&SP&TR "<<endl;
	return 0;
	}
