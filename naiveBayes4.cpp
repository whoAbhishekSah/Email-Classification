//Genreating the map for count of each word over all the docs of a particular class;

#include <bits/stdc++.h>
using namespace std;


bool validWord(string word){
	if (word.length()<=2 || word.length()>=12)
		return false;
	return true;
}

int main(int argc, char const *argv[])
{
	int count=0;
	map<string, int> wordCounter;
	map<string, int>::iterator it;
	ifstream file;
	ofstream outfile;
	file.open("vocabularyEntertainment.txt");
	outfile.open("countEntertainment.txt");
	string word;
	int noOfWord=0;
	while(file>>word){
		//cout<<word<<"\t";
		if (validWord(word)==false) continue; 
		if (wordCounter.find(word) == wordCounter.end()) {
			wordCounter.insert(pair<string,int>(word,0));
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
	cout<<endl<<noOfWord<<"\twith total occurences\\t"<<count<<endl;
	outfile<<count<<endl;
	return 0;
}