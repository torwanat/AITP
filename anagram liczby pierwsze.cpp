#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	string m,n;
	cout<<"Podaj wyraz pierwszy: ";
	cin>>m;
	cout<<"Podaj wyraz drugi: ";
	cin>>n;
	for(int i=0; i<m.size(); i++){
		m[i]=toupper(m[i]);
	}
	for(int i=0; i<n.size(); i++){
		n[i]=toupper(n[i]);
	}
}
