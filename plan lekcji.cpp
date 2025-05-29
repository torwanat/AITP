#include<iostream>

using namespace std;

int main()
{
	int n,h=0,tmp=0;
	int k[100];
	
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>k[i];
	}
	
	for(int i=1;i<n;i++){
		if(k[i-1]==1 && k[i+1]==1) k[i]=1;
	}

	
	for(int i=0;i<n;i++){
		if (k[i]!=0) h++;
	}
	cout<<h;
}
