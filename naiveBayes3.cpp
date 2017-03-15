//To construct the vocabulary from all the training docs.

#include <bits/stdc++.h>
using namespace std;

bool validWord(string word){
	if (word.length()<=2 || word.length()>=12)
		return false;
	return true;
}

int main(int argc, char const *argv[]){
	ifstream file;
	ofstream outfile;
	outfile.open("dictionary.txt");
	file.open("vocabulary.txt");
	string word;
	set<string> vocabulary;
	set<string>::iterator itr;
	int i=0;
	while(file>>word){
		//cout<<word<<"\t";
		if (validWord(word)==false) continue; 
		vocabulary.insert(word);
		i++;
	} 
	cout<<"Count is \t"<<i<<"\t size of set is \t"<<vocabulary.size()<<endl;	

	 for (itr = vocabulary.begin(); itr != vocabulary.end(); ++itr){
        outfile<<*itr<<endl;
        cout<<*itr<<"\t";
 	}

    //cout<<"Count is \t"<<vocabulary.size()<<endl;	
	file.close();
	return 0;
}