#include<iostream>

using namespace std;
int a;
int b;

int prosto(int a, int b);

int main(){
	cin>>a>>b;
	cout<<prosto(a,b);
}

int prosto(int a,int b){
	a*=b;
	return a;
}
