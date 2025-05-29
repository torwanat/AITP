#include<iostream>

using namespace std;

int pt(int a, int b);
int main(){
	int a,b;
	cin>>a>>b;
	cout<<pt(a,b);
}
int pt(int a, int b)
{
    if (b == 1)
    return a;
    int s = pt(a, b - 1);
    return a * s;
}
