#include<iostream>

using namespace std;

int main()
{
	unsigned int a; 
	long long s = 1; 

	cin>>a;

	for(int i=a;i>1;i--)
	s = s * i;

	cout<<s<<endl;

}
