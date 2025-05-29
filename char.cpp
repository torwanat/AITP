#include<iostream>

using namespace std;

int main()
{
	char c;     //amiana znaku na ascii
	cout<<"podaj znak ";
	cin>>c;
	cout<<"podales "<<c;
	int ascii = c;
	cout<<endl<<"w ascii "<<ascii<<endl;
	
	c='4';   //zamiana liczb na ascii
	int x = c - 48; //lub x = c - '0'
	ascii = c;
	
	cout<<"cyfra= "<<c<<" to w ascii "<<ascii<<endl;  //z normalnego do ascii
	cout<<"po zamianie na liczbe= "<<x<<endl;         //i z powrotem
	
	c = 4; //oznacza [EOT]
	cout<<c<<endl;
}
