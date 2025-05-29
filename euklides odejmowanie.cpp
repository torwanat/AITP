#include<iostream>

using namespace std;

int main()
{
	int a,b,c;
	cout<<"podaj a i b";
	cin>>a>>b;
	
	while(b!=0)
	{
		c=a%b;
		a=b;
		b=c;
	}
	cout<<"NWD="<<a<<endl;
	system("pause");
	return 0;
}
