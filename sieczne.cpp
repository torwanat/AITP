#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib> 

using namespace std;

double f(double x)
{
  return pow((x-5),3);
}

int main()
{
	double a,b,x0,x1,fa,fb,f0,eps;
	cout<<"Podaj a: ";
	cin>>a;
	cout<<"Podaj b: ";
	cin>>b;
	cout<<"Podaj epsilon: ";
	cin>>eps;
	fa=f(a);fb=f(b);x1=a;x0=b;
	while(fabs(x1-x0)>eps)
    {
      x1=x0;
      x0=a-fa*(b-a)/(fb-fa);
      f0=f(x0);
      if(fa*f0<0)
      {
        b=x0; 
		fb=f0;
      }
      else
      {
        a=x0;
		fa=f0;
      }
    }
    cout<<x0;
	return 0;
}

