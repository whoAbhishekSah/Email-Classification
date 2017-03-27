#include<iostream>
#include "bigint.cpp"
using namespace std;
int main()
	{
	string a;
	cin>>a;
	string b;
	cin>>b;
	BigInteger obj;
	cout<<obj.greater(a,b);
	return 0;
	}
