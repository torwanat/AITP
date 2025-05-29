#include<iostream>

using namespace std;

int euklides(int a,int b){
	if(b==0)
	return a;
	else return euklides(b,a%b);
}
int main()
{
	int m,n;
	cin>>m>>n;
	cout<<euklides(m,n);
}
