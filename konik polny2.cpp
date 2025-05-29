#include<iostream>

using namespace std;

int main()
{
	int x,s,i,c;
	cin>>x>>s;
	c=0;
	for(i=s;x>0;i=i/2){
		if(i<1){
		i=1;
		}
		x-=i;
		c+=1;
	}
	cout<<c;
}
