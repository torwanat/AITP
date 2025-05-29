#include<iostream>

using namespace std;

int main(){
	int i, a, il, n;
	cin>>n;
	il=1;
	for(i=0;i<n;i++){
		cin>>a;
		il *= a;
	}
	cout<<il;
}
