#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

double epsilon=0.00001;
double a=-1000;
double b=1000;
double t=10000;

double f(double x)
{
	return (2*x+3*(x*x));
}

double g(double x){
	return 1+1/x; 
}

double h(double x){
	return 1+3*(x*x);
}
double j(double x){
	return 9+12*x+3*(x*x);
}
double p(double a,double b,double e){
	if(f(a)==0)return a;
	if(f(b)==0)return b;
	double s=(a+b)/2;
	if(b-a<=e)return s;
	if(f(a)*f(s)<0){
		return p(a, s, e);}
	return p(s, b, e);
}

double u(double a,double b, double eps){
	double fa,fb,x1,x0,f0;
	fa=f(a);
	fb=f(b);
	x1=a;
	x0=b;
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
    return x0;
}

double p1(double a,double b,double e){
	if(g(a)==0)return a;
	if(g(b)==0)return b;
	double s=(a+b)/2;
	if(b-a<=e)return s;
	if(g(a)*g(s)<0){
		return p1(a, s, e);}
	return p1(s, b, e);
}
double p2(double a,double b,double e){
	if(h(a)==0)return a;
	if(h(b)==0)return b;
	double s=(a+b)/2;
	if(b-a<=e)return s;
	if(h(a)*h(s)<0){
		return p2(a, s, e);}
	return p2(s, b, e);
}
double p3(double a,double b,double e){
	if(j(a)==0)return a;
	if(j(b)==0)return b;
	double s=(a+b)/2;
	if(b-a<=e)return s;
	if(j(a)*j(s)<0){
		return p3(a, s, e);}
	return p3(s, b, e);
}
double u1(double a,double b, double eps){
	double fa,fb,x1,x0,f0;
	fa=g(a);
	fb=g(b);
	x1=a;
	x0=b;
	while(fabs(x1-x0)>eps)
    {
      x1=x0;
      x0=a-fa*(b-a)/(fb-fa);
      f0=g(x0);
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
    return x0;
}
double u2(double a,double b, double eps){
	double fa,fb,x1,x0,f0;
	fa=h(a);
	fb=h(b);
	x1=a;
	x0=b;
	while(fabs(x1-x0)>eps)
    {
      x1=x0;
      x0=a-fa*(b-a)/(fb-fa);
      f0=h(x0);
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
    return x0;
}
double u3(double a,double b, double eps){
	double fa,fb,x1,x0,f0;
	fa=j(a);
	fb=j(b);
	x1=a;
	x0=b;
	while(fabs(x1-x0)>eps)
    {
      x1=x0;
      x0=a-fa*(b-a)/(fb-fa);
      f0=j(x0);
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
    return x0;
}
int main(){
	cout<<p(a,b,epsilon)<<endl;
	cout<<u(a,b,epsilon)<<endl;
	cout<<p1(a,b,epsilon)<<endl;
	cout<<u1(a,b,epsilon)<<endl;
	cout<<p2(a,b,epsilon)<<endl;
	cout<<u2(a,b,epsilon)<<endl;
	cout<<p3(a,b,epsilon)<<endl;
	cout<<u3(a,b,epsilon)<<endl;
}
