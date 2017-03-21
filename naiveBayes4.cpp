//Genreating the map for count of each word over all the docs of a particular class;

#include <bits/stdc++.h>
using namespace std;


vector<string> split(string test){
	string temp="";
	std::vector<string> words;
	for (int i=0; i<test.size(); i++){
		temp+=test[i];
		if (test[i]==' ') {
			//cout<<temp<<"\t";
			temp="";
			words.push_back(temp);
		}
	}
	return words;
}


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
	file.open("social.txt");
	outfile.open("countSocial.txt");
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
	outfile<<count<<endl;
	cout<<endl<<wordCounter.size()<<"\twith total occurences in social\t"<<count<<endl;

	file1.open("bussiness.txt");
	outfile1.open("countBusiness.txt");
	noOfWord=0, count=0;
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
	    outfile << it->first<< "\t:"<< it->second<<endl;
	    count+=it->second;
	}

	cout<<endl<<wordCounter1.size()<<"\twith total occurences in business \t"<<count<<endl<<endl<<endl;
	int count1=0, count2=0;
	ifstream file2;
	file2.open("test.txt");
	string test;
	while(getline(file2, test)){
		cout<<test<<endl;
		std::vector<string> words = split(test);
		cout<<words.size()<<endl<<endl<<endl;
		long long q,r, temp=1, temp1=1;
		for (int y=0; y<words.size(); y++){			//need to find no. of occurences in each class.
			//class education
			bool found=true;
			if (wordCounter.find(word) != wordCounter.end()){
				q=wordCounter[word];
				temp=(temp*q)%100000007;
			}
			else
				count1++;
			if (wordCounter1.find(word) != wordCounter1.end()){
				r=wordCounter1[word];
				temp1=(temp1*r)%100000007;
			}
			else
				count2++;
			
		}
		cout<<"Not found in social\t"<<count1<<"\t Not found in business\t"<<count2<<endl<<endl<<endl;
		cout<<"Business probabilty\t"<<temp<<"\t"<<"Social probabilty\t"<<temp1<<"\n";
		if (temp>temp1) cout<<"business\n";
		else cout<<"social\n";

	}
	
	return 0;
}