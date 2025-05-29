#include <iostream>
#include <cstdlib>

using namespace std;

double f(double x){
	return x*x;
}

int main()
{
    double p,k,h,c,n;
    p=-1;
    k=1;
    n = 4;
    h=(k-p)/n;
    c=0;
    for(int i=1; i<=n; i++)
    {
        c+=f(p+i*h)*h;
    }
    cout<<"Wynik: "<<c<<endl;
    return 0;
}
