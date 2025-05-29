#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "ClassMatrix.hpp"
#include "FunctionsMatrix.cpp"
using namespace std;
matrix AddMatrix(matrix m1, matrix m2);
matrix MuliplyByValueMatrix(matrix m1, int k, int m, int n);
matrix MultiplyByOtherMatrix(matrix m1, matrix m2);
int main()
{
	srand(time(NULL));
	int x,y,k,small;
	string name;
	cout<<"Podaj wysokosc oraz szerokosc macierzy"<<endl;
	cin>>x>>y;
	cout<<endl;
	if(x<y)
		small=x;
	else
		small=y;

	matrix m1;
	m1.create(x,y);
	m1.fill();
	cout<<"M1:\n";
	m1.show();

	matrix m2;
	m2.create(x,y);
	m2.fill();
	cout<<"M2:\n";
	m2.show();

	matrix m3=m1+m2;
	cout<<"M3 po dodaniu:\n";
	m3.show();

	cout<<"Podaj liczbe do pomnozenia: \n";
	cin>>k;
	cout<<endl;
	matrix PDST(x,y, "PDST");
	PDST.fill();
	cout<<"Tablica podstawowa: \n";
	PDST.show();

	//matrix m4(MuliplyByValueMatrix(PDST, k));
	matrix m4=PDST*k;
	cout<<"M4: Podstawowa po pomnozeniu przez liczbe: \n";
	m4.show();

	matrix m5, m6;
	m5.create(x,y);
	m5.fill();
	cout<<"M5: \n";
	m5.show();

	m6.create(x,y);
	m6.fill();
	m6.Transpozycja();
	cout<<"M6: \n";
	m6.show();

	//matrix m7(MultiplyByOtherMatrix(m5,m6));
	matrix m7=m5*m6;
	cout<<"M7: M5*M6: \n";
	//m7.show();
	cout<<m7;

	
	cout<<endl<<"Zabawa z M8: \n"<<endl;
	matrix m8(x,y,"m8");
	cin>>m8;
	cout<<m8;
	
	cout<<"Wyznacznik m8: \n";
	cout<<m8.Wyznacznik();

	return 0;
}
