#include<iostream>

using namespace std;

unsigned long long fibo( int n){
	if(n == 0)
{
    return 0;
}
else if(n == 1)
{
    return 1;
}
else
{
    return fibo(n - 1) + fibo(n - 2);

}}
int main(){
	int x;
	cin>>x;
	cout<<fibo(x);
}
