#include<iostream>

using namespace std;

int suma1(int x, int y);
void suma2(int x, int y);
int suma3(void);
void suma4(void);

int x=2,y=5;
int main(){
	int a,b;
	cout<<"podaj liczby\n";
	cin>>a>>b;
	//suma1
	int wynik=suma1(a,b);
	cout<<a<<"+"<<b<<"="<<wynik<<endl;
	//albo
	cout<<a<<"+"<<b<<"="<<suma1(a,b)<<endl;
	//suma2
	cout<<a<<"+"<<b<<"=";
	suma2(a,b);
	//suma3
	cout<<x<<"+"<<y<<"="<<suma3()<<endl;
	//suma4
	cout<<x<<"+"<<y<<"=";
	suma4();
	system("pause");
	return 0;	
}
int suma1(int x, int y)
{
	return x+y;
}
void suma2(int x, int y){
	cout<<x+y<<endl;
}
int suma3(void){
	return  x+y;
}
void suma4(void){
	cout<<x+y;
}
