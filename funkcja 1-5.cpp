#include<iostream>

using namespace std;

int f(int a);

int main(){
	int a;
	cin>>a;
	cout<<f(a);
}

int f(int a){
	a*=a;
	a++;
	return a;
}
