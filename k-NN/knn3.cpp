/* This code is previous version of knn considering frequency and id as weight*/
#include<iostream>
#include<fstream>
#include<map>
#include<set>
#include<iterator>
#include<math.h>
#include<vector>
#include<sstream>
using namespace std;
map<string,int>test;
map<string,int> **train;
map<string,int> vocab;
vector<long double> simBusiness;
vector<long double> simEducation;
vector<long double> simSocial;
vector<long double> simSports;
vector<long double> simEntertainment;
long double confBusiness;
long double confSocial;
long double confSports;
long double confEntertainment;
long double confEducation;
void make_test()
	{
	ifstream file;	
	file.open("test_file_vector.txt");
	string input;	
	while(file>>input)
		++test[input];
	}
void createvocab()
	{
	ifstream file;
	file.open("uniquewords2/finalvocab.txt");
	string input;
	string str;
	int freq;
	while(file>>input)
		{
		file>>str;
		file>>freq;
		vocab[input]=freq;
		}
	file.close();
	}
void calConf()
	{
	long double confNum=0;
	long double confDen=0;
	for(int i=1;i<simBusiness.size();i++)
		confNum=confNum+simBusiness[i];
	long double simBuss=confNum;
	confNum=0;
	confDen=0;
	for(int i=1;i<simSocial.size();i++)
		confNum=confNum+simSocial[i];
	long double simSoc=confNum;
	confNum=0;
	confDen=0;
	for(int i=1;i<simEducation.size();i++)
		confNum=confNum+simEducation[i];
	long double simEdu=confNum;
	confNum=0;
	confDen=0;	
	for(int i=1;i<simSports.size();i++)
		confNum=confNum+simSports[i];
	long double simSpo=confNum;
	confNum=0;
	confDen=0;
	for(int i=1;i<simEntertainment.size();i++)
		confNum=confNum+simEntertainment[i];
	long double simEnt=confNum;
	confDen=simBuss+simSoc+simEdu+simSpo+simEnt;
	confBusiness=simBuss/confDen;
	confEducation=simEdu/confDen;
	confEntertainment=simEnt/confDen;
	confSports=simSpo/confDen;
	confSocial=simSoc/confDen;
	}
void euc_sim(map<string,int> train,int clasno)
	{
	set<string> common;
	for(map<string,int>::iterator it=test.begin();it!=test.end();it++)
		{
		if(train.end()!=train.find(it->first))
			common.insert(it->first);
		}
	if(common.size()==0)
		{
		if(clasno==1)
			simBusiness.push_back(0);	
		if(clasno==2)
			simEducation.push_back(0);	
		if(clasno==3)
			simSocial.push_back(0);	
		if(clasno==4)
			simEntertainment.push_back(0);	
		if(clasno==5)
			simSports.push_back(0);	
		return;		
		}
	long double sum=0;
	long double d1=0;
	long double d2=0;
	long double N=4438.0;
	int n;
	long double id;
	long double weight1;
	long double weight2;
	for(set<string>:: iterator it=common.begin();it!=common.end();it++)
		{
		n=vocab[*it];
		id=log10(N/n);
		weight1=train[*it]*id;
		weight2=test[*it]*id;
		sum=sum+(weight1)*(weight2);		
		d1=d1+weight1*weight1;
		d2=d2+weight2*weight2;				
		}
	long double den=sqrt(d1)*sqrt(d2);
	long double sim=sum/den;
	if(clasno==1)
		simBusiness.push_back(sim);	
	if(clasno==2)
		simEducation.push_back(sim);	
	if(clasno==3)
		simSocial.push_back(sim);	
	if(clasno==4)
		simEntertainment.push_back(sim);	
	if(clasno==5)
		simSports.push_back(sim);	
	}																																void make_train(int i,int j,string file_name)
	{
	ifstream file;	
	file.open(file_name.c_str());
	string input;
	string str;
	int freq;	
	while(file>>input)
		{
		file>>str;
		file>>freq;
		train[i][j][input]=freq;	
		}
	file.close();	
	}
int main()
	{
	simBusiness.push_back(0);
	simEducation.push_back(0);
	simEntertainment.push_back(0);
	simSocial.push_back(0);
	simSports.push_back(0);
	make_test();
	createvocab();
	stringstream s1;
	string str;
	train=new map<string,int>*[6];
	train[1]=new map<string,int>[1001];
	train[2]=new map<string,int>[1001];
	train[3]=new map<string,int>[1001];
	train[4]=new map<string,int>[720];
	train[5]=new map<string,int>[720];
	for(int i=1;i<=1000;i++)
		{
		s1<<i;
		s1>>str;
		string file_name="stemmedclassesfreq2/business2/"+str+".txt";
		make_train(1,i,file_name);
		s1.clear();
		}
	for(int i=1;i<=1000;i++)
		{
		s1<<i;
		s1>>str;
		string file_name="stemmedclassesfreq2/education2/"+str+".txt";
		make_train(2,i,file_name);
		s1.clear();
		}
	for(int i=1;i<=1000;i++)
		{
		s1<<i;
		s1>>str;
		string file_name="stemmedclassesfreq2/social2/"+str+".txt";
		make_train(3,i,file_name);
		s1.clear();
		}
	for(int i=1;i<=719;i++)
		{
		s1<<i;
		s1>>str;
		string file_name="stemmedclassesfreq2/entertainment2/"+str+".txt";
		make_train(4,i,file_name);
		s1.clear();
		}
	for(int i=1;i<=719;i++)
		{
		s1<<i;
		s1>>str;
		string file_name="stemmedclassesfreq2/sports2/"+str+".txt";
		make_train(5,i,file_name);
		s1.clear();
		}
	for(int i=1;i<=1000;i++)
		euc_sim(train[1][i],1);
	for(int i=1;i<=1000;i++)
		euc_sim(train[2][i],2);
	for(int i=1;i<=1000;i++)
		euc_sim(train[3][i],3);
	for(int i=1;i<=719;i++)
		euc_sim(train[4][i],4);
	for(int i=1;i<=719;i++)
		euc_sim(train[5][i],5);

	calConf();
	cout<<"Business  "<<confBusiness<<endl;
	cout<<"Education  "<<confEducation<<endl;
	cout<<"Social  "<<confSocial<<endl;
	cout<<"Sports  "<<confSports<<endl;
	cout<<"Entertainment  "<<confEntertainment<<endl;
	long double maxx=max(max(max(max(confEntertainment,confSports),confSocial),confEducation),confBusiness);
	cout<<maxx<<endl;
	if(maxx==confBusiness)
		cout<<"It's Business"<<endl;
	if(maxx==confEducation)
		cout<<"It's Education"<<endl;
	if(maxx==confSocial)
		cout<<"It's Social"<<endl;
	if(maxx==confEntertainment)
		cout<<"It's Entertainment"<<endl;
	if(maxx==confSports)
		cout<<"It's Sports"<<endl;
  	return 0;
	}
