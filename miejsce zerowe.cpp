#include<iostream>
#include<iomanip>
#include <cmath>
using namespace std;

double f(double x)
{
	return pow((x-5),3);
}

double p(double a,double b,double epsilon)
{
	if(f(a)==0)return a;
	if(f(b)==0)return b;
	
	double s;
	
	while(b-a>epsilon)
	{
		s=(a+b)/2;
		
		if(f(s)==0) 
			return s;
		if(f(a)*f(s)<0) 
			b=s;
		else
			a=s;
	}
	return(a+b)/2;
}

int main()
{
	double a,b,epsilon;
	cout<<"Podaj a (liczba niedodatnia): ";
	cin>>a;
	cout<<"Podaj b: ";
	cin>>b;
	cout<<"Podaj epsilon: ";
	cin>>epsilon;
	cout<<"Miejsce zerowe wynosi: ";
	cout<<p(a, b, epsilon);
	return 0;
}
