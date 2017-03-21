//To construct the vocabulary from all the training docs.

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]){
	ifstream file;
	ofstream outfile;
	outfile.open("dictionary.txt");
	file.open("vocabulary.txt");
	string word;
	set<string> vocabulary;
	set<string>::iterator itr;
	int i=0;
	int x=0;
	while(file>>word){
		vocabulary.insert(word);
		x++;
		i++;
	} 
	cout<<"Count is \t"<<i<<"\t size of set is \t"<<vocabulary.size()<<endl;	

	 for (itr = vocabulary.begin(); itr != vocabulary.end(); ++itr){
       	outfile<<*itr<<endl;
        //cout<<*itr<<"\t";
 	}

    cout<<"Iterated over \t"<<x<<"\tCount of set is \t"<<vocabulary.size()<<endl;	
	file.close();
	return 0;
}