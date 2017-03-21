#include<iostream>
#include<fstream>
using namespace std;
int main()
	{
	ifstream file;
	file.open("bussiness.txt");
	ofstream file2;
	file2.open("bussiness2.txt");
	string word;
	int count=0;
	cout<<count<<endl;
	while(file>>word && count<=250000)
		{
		cout<<count<<endl;
		count++;
		cout<<word<<endl;
		file2<<word<<endl;
		}
	file.close();
	file2.close();
	return 0;
	}
