#include<iostream>

using namespace std;

int main()
{
	double a,b,c;
	cout<<"Podaj a\n";
	cin>>a;
	
	do{
		cout<<"Podaj b\n";
		cin>>b;
	}while(b==0);
	c=a/b;
    cout<<a<<"/"<<b<<"="<<c<<endl;
		
	
	return 0;
}
