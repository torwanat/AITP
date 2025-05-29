#include<iostream>
#include <cmath>
using namespace std;

double f(double x)
{
	return pow((x-5),3);
}

double p(double a,double b,double e)
{
	if(f(a)==0)return a;
	if(f(b)==0)return b;
	double s=(a+b)/2;
	if(b-a<=e)return s;
	if(f(a)*f(s)<0){
		return p(a, s, e);}
	return p(s, b, e);
}
int main()
{
	double a,b,epsilon;
	cout<<"Dla najlepszego dzialania programu, a powinno byc duza liczba ujemna, b duza liczba dodatnia, a epsilon jak najmniejszy"<<endl;
	cout<<"Podaj a: ";
	cin>>a;
	cout<<"Podaj b: ";
	cin>>b;
	cout<<"Podaj epsilon: ";
	cin>>epsilon;
	cout<<"Miejsce zerowe wynosi: ";
	cout<<p(a, b, epsilon);
	return 0;
}
