#include<iostream>

using namespace std;

int main()
{
	int a,b,c;
	cout<<"podaj a i b";
	cin>>a>>b;
	while(b!=0)
	{
		if(a>b)
			a=a-b;
		else;
		b=b-a;
	}
		cout<<"NWD="<<a<<endl;
	system("pause");
	return 0;
}
