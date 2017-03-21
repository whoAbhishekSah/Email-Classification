//Genreating the map for count of each word over all the docs of a particular class;

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int count=0;
	map<string, int> wordCounter;	//education
	map<string, int> wordCounter1;	//business
	set<string> vocabulary;
	set<string>::iterator itr;
	map<string, int>::iterator it;
	ifstream file;
	ifstream file1;
	ofstream outfile;
	ofstream outfile1;
	file.open("education.txt");
	outfile.open("countEducation.txt");
	string word;
	int noOfWord=0;
	while(file>>word){
		if (wordCounter.find(word) == wordCounter.end()) {
			wordCounter.insert(pair<string,int>(word,0));
			vocabulary.insert(word);
			noOfWord++;
		}
		else {
		  int r=wordCounter[word];
		  r++;
		  wordCounter[word]=r;
		}
	}
	for (it = wordCounter.begin(); it != wordCounter.end(); it++ ){
	    outfile << it->first<< "\t:"<< it->second<<endl;
	    count+=it->second;
	}
	cout<<endl<<wordCounter.size()<<"\twith total occurences in education\t"<<count<<endl;

	file1.open("bussiness2.txt");
	outfile1.open("countBusiness.txt");
	noOfWord=0; count=0;
	while(file1>>word){
		//cout<<word<<"\t";
		if (wordCounter1.find(word) == wordCounter1.end()) {
			wordCounter1.insert(pair<string,int>(word,0));
			vocabulary.insert(word);
			noOfWord++;
		}
		else {
		  int r=wordCounter1[word];
		  r++;
		  wordCounter1[word]=r;
		}
	}
	
	for (it = wordCounter1.begin(); it != wordCounter1.end(); it++ ){
	    outfile1 << it->first<< "\t:"<< it->second<<endl;
	    count+=it->second;
	}

	cout<<endl<<wordCounter1.size()<<"\twith total occurences in business \t"<<count<<endl<<endl<<endl;
	cout<<"\nsize of vocabulary\t"<<vocabulary.size()<<endl;

	ifstream file2;
	file2.open("test.txt");
	string test;
	int count1=0, count2=0;
	long long q,r; long long temp=1, temp1=1;
	while(getline(file2, test)){
		cout<<"Line being checked:\t"<<test<<endl;
		string temp3="";
		for (int i=0; i<test.size(); i++){
			temp3+=test[i];
			if (test[i]==' ') {
				cout<<temp3<<"\n";
				
				//class education
				if (wordCounter.find(temp3) == wordCounter.end()){
					count1++;	
				}
				else{
					q=wordCounter[temp3];
					cout<<temp3<<"found in education\t"<<q<<"\tNo of time\n";
					temp=(temp*q);
				}
					
				//class business
				if (wordCounter1.find(temp3) == wordCounter1.end()){
					count2++;
				}
				else{
					r=wordCounter1[temp3];
					cout<<temp3<<"found in education\t"<<q<<"\tNo of time\n";
					temp1=(temp1*r);
				}
				temp3="";
			}
		}
		cout<<"\nNot found in education\t"<<count1<<"\t Not found in business\t"<<count2<<endl<<endl<<endl;
		cout<<"Business probabilty\t"<<temp<<"\t"<<"education probabilty\t"<<temp1<<"\n";
		if (temp>temp1) cout<<"business\n";
		else cout<<"education\n";

	}
	
	return 0;
}