#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream in;
ofstream out;

int main(){
	string tekst=" ";
	
	out.open("dane.txt");
	if(out.good()){
		cout<<"Napisz cos: "<<endl;
		getline(cin,tekst);
		out<<tekst;
		out.close();
	}else
	cout<<"Blad utworzenia pliku"<<endl;
	
	in.open("dane.txt");
	if(in.good()){
		cout<<"Zapisales w pliku"<<endl;
		while(!in.eof()){
			getline(in,tekst);
			cout<<tekst;
		}
		cout<<endl;
		in.close();
	}else
	cout<<"Blad otwarcia pliku"<<endl;
	return 0;
}
