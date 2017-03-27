#include <bits/stdc++.h>
using namespace std;

int main(){
	ifstream file;
    ofstream outfile;
    outfile.open("vocabulary.txt");
    int x=4;
    for (int x=3; x<10; x++){
        std::string s;
        std::stringstream out;
        out << x;
        s = out.str();
        s=s+".txt";
        cout<<s.c_str()<<endl;
        try{
            file.open(s.c_str());
            file.exceptions ( ifstream::eofbit | ifstream::failbit | ifstream::badbit );
            string word;
            int i=0;
            while (file >> word)
            {
                i++;
                if (word.length()>2){
                    cout<< word << '\t';
                    outfile<<word+"\n";
                } 
            }
            cout<<i<<endl;
        }
        catch(std::exception e){
            cout << "There was an error: " << e.what() << endl;
            continue;
        }
    }
    
	return 0;
}