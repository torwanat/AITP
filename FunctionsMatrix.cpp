#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "ClassMatrix.hpp"
matrix::matrix(){
	m=0;
	n=0;
	name="a";
}
void matrix::create(int x, int y){
	m=x;
	n=y;
	a = new int *[m];
	for(int i=0; i<m; i++)
		a[i]= new int [n];

}
matrix::matrix(int x,int y,string N){
	m=x;
	n=y;
	name=N;
	create(m,n);
}
matrix::matrix(const matrix& oryginal) {

	m = oryginal.get_m();
	n = oryginal.get_n();
	a = new int*[m];
 	for (int i = 0; i < m; i++)
  	{
    	a[i] = new int[n];
    	for (int j = 0; j < n; j++)
			a[i][j] = oryginal.get_a(i,j);
  	}
}
void matrix::set(int x,int y,string NAME){
	m=x;
	n=y;
	name=NAME;
}
int matrix::get_m()const{
	return m;
}
int matrix::get_n()const{
	return n;
}
string matrix::get_name()const{
	return name;
}
void matrix::fill(){
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			a[i][j]=rand()%9+1;
}
void matrix::show()const{
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<" "<<a[i][j]<<" ";
			if(a[i][j]<10)
				cout<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";
}
int matrix::get_a(int m, int n)const {
	return a[m][n];
}
void matrix::set_a(int m, int n, int value){
	a[m][n]=value;
}

int matrix::Wyznacznik() {
	int temp=0, value=0;
	int hasJumpedM=1, hasJumpedN=0;
	
	
	if(m==1 && n==1) {
		return a[0][0];
	}else if (m==2 && n==2) {
		temp=(a[0][0]*a[1][1])-(a[1][0]*a[0][1]);
		return temp;
	}
	//Do tutaj bezpiecznie
	matrix Mat[m];
	for(int i=0; i<m; i++) {
		Mat[i].create(m-1,n-1);
		
		for(int j=0; j<m; j++) {
			hasJumpedN=0;
			for(int k=0; k<n; k++) {
				if(k>=i) {
					hasJumpedN=1;
				}
				if (j+hasJumpedM==m || k+hasJumpedN==n) {
					continue;
				}
				temp=a[j+hasJumpedM][k+hasJumpedN];
				Mat[i].set_a(j,k,temp);
			}
		}
	}
	
	for(int i=0; i<m; i++) {
		value += get_a(0,i)*Mat[i].Wyznacznik()*pow(-1,(double)i);
	}
	
	return value;
	
}
void matrix::Transpozycja(){
	int temp;
	int **b;
	b = new int *[m];
	for(int i=0; i<m; i++)
		b[i]= new int [n];
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			b[i][j]=a[i][j];
	a=NULL;
	temp=m;
	m=n;
	n=temp;
	create(m,n);
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			a[i][j]=b[j][i];
	for(int i=0; i<n; i++)
		delete[] b[i];
	delete[] b;
}
matrix AddMatrix(matrix m1, matrix m2) {
	matrix sum;
	sum.create(m1.get_m(), m1.get_n());
	for(int i=0; i<m1.get_m(); i++)
		for(int j=0; j<m1.get_n(); j++)
			sum.set_a(i,j, (m1.get_a(i,j)+m2.get_a(i,j)));

	return sum;
}
matrix MuliplyByValueMatrix(matrix given, int k) {
  matrix result;
  result.create(given.get_m(), given.get_n());
  for (int i = 0; i < result.get_m(); i++)
  	for (int j = 0; j < result.get_n(); j++)
		result.set_a(i, j, given.get_a(i,j) * k);
  return result;
}
matrix MultiplyByOtherMatrix(matrix m1, matrix m2) {
	int k, temp=0, m=m1.get_m(), n=m1.get_n();
	matrix result;
	if(n>m){
		k=n;
		n=m;
	}
	else{
		k=m;
		m=n;
	}
	result.create(m,n);

	for(int i=0; i<result.get_m(); i++)
		for(int j=0; j<result.get_n(); j++)
			result.set_a(i,j,0);

	if(m1.get_m()<m1.get_n()){
		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++)
				for(int r=0; r<k; r++){
					temp = result.get_a(i,j)+(m1.get_a(i,r)*m2.get_a(r,j));
					result.set_a(i,j,temp);
				}
	}
	else{
		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++)
				for(int r=0; r<k; r++){
					temp = result.get_a(j,i)+(m1.get_a(r,i)*m2.get_a(j,r));
					result.set_a(j,i,temp);
				}
	}
	return result;
}
matrix operator+(matrix a, matrix b) {
	matrix tmp(a.m, a.n, "tmp");

	for(int i=0; i<tmp.m; i++)
		for(int j=0; j<tmp.n; j++)
			tmp.a[i][j]= a.a[i][j] + b.a[i][j];


	return tmp;
}
matrix operator*(matrix given, int k) {
    matrix result;
    result.create(given.m, given.n);
    for (int i = 0; i < result.m; i++)
        for (int j = 0; j < result.n; j++)
            result.a[i][j] = (given.a[i][j] * k);
    return result;
}
matrix operator*(matrix given1, matrix given2) {
    int k, temp=0, m1=given1.m, n1=given1.n;
	matrix result;
	if(n1>m1){
		k=n1;
		n1=m1;
	}
	else{
		k=m1;
		m1=n1;
	}
	result.create(m1,n1);

	for(int i=0; i<result.m; i++)
		for(int j=0; j<result.n; j++)
			result.a[i][j]=0;

	if(given1.m<given1.n){
		for(int i=0; i<m1; i++)
			for(int j=0; j<n1; j++)
				for(int r=0; r<k; r++){
					temp = result.a[i][j]+(given1.a[i][r] * given2.a[r][j]);
					result.a[i][j]=temp;
				}
	}
	else{
		for(int i=0; i<m1; i++)
			for(int j=0; j<n1; j++)
				for(int r=0; r<k; r++){
					temp = result.a[j][i] +(given1.a[r][i] *given2.a[j][r] );
					result.a[j][i]=temp;
				}
	}
	return result;
}

ostream& operator<<(ostream& s, matrix a) {

    for(int i=0; i<a.m; i++)
	{
		for(int j=0; j<a.n; j++)
		{
			s<<" "<<a.get_a(i,j)<<" ";
			if(a.get_a(i,j)<10)
				s<<" ";
		}
		s<<"\n";
	}
	s<<"\n";

	return s;
}

istream& operator>>(istream& s, matrix& a) {
	for(int i=0; i<a.m; i++) {
		for(int j=0; j<a.n; j++) {
			s >> a.a[i][j];
		}
	}
	return s;
}

matrix::~matrix() {
  for (int i = 0; i < m; i++) delete[] a[i];
  delete[] a;
}




