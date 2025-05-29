#include<iostream>

using namespace std;

unsigned long long silnia(int n){
	if(n==0) return 1;
	else return n*silnia(n-1);
}
int main(){
	int x;
	cin>>x;
	cout<<silnia(x)<<endl;
	system("pause");
	return 0;
}
