#ifndef MATRIX_CPP
#define MATRIX_CPP 1

#include"matrix.h"

template<typename t1>
void matrix<t1>::alloc(ull _n, ull _m)
{
	tab = new t1 *[_n];
	rep(i,_n){
		tab[i] = new t1[_m];
		rep(j,_m) tab[i][j]=0;
	}
}
template<typename t1>
void matrix<t1>::create(ull _n, ull _m)
{
	alloc(_n,_m);
	n=_n;
	m=_m;
}
template<typename t1>
void matrix<t1>::destroy(){if(tab!=nullptr){rep(i,n) delete tab[i]; delete tab;}}
template<typename t1>
matrix<t1>::matrix(const matrix &m2)
{
	n=m2.n;
	m=m2.m;
	tab = new t1 *[n];
	rep(i,n) tab[i] = new t1 [m];
		rep(i,n){
			rep(j,m){
			tab[i][j]=m2.tab[i][j];
		}
	}
}
template<typename t1>
matrix<t1>::matrix(matrix &&m2)
{
	n=m2.n;
	m=m2.m;
	tab=m2.tab;
	m2.tab=nullptr;
}
template<typename t1>
matrix<t1>::matrix(ull _n, ull _m): n(_n), m(_m)
{
	create(_n,_m);
}
template<typename t1>
matrix<t1>::matrix(ull _n, ull _m, string _name): n(_n), m(_m), name(_name)
{
	create(_n,_m);
}
template<typename t1>
matrix<t1>::matrix(initializer_list<initializer_list<t1>> _l)
{
	n=_l.size();
	m=_l.begin()->size();
	tab = new t1 *[_l.size()];
	ull i2=0, j2=0;
	for(auto &i : _l){
		j2=0;
		tab[i2] = new t1[i.size()];
		if(i.size()!=m) cout<<"WARNING! matrix not rectangular!\n";
		for(auto &j : i){
			tab[i2][j2]=j;
			++j2;
		}
		++i2;
	}
}
template<typename t1>
matrix<t1>::~matrix(){destroy();}
template<typename t1>
matrix<t1>& matrix<t1>::operator = (const matrix &other)
{
	if(this != &other)
	{
		destroy();
		n=other.n;
		m=other.m;
		tab = new t1 *[n];
		rep(i,n){
			tab[i] = new t1[m];
			rep(j,m) tab[i][j]=other.tab[i][j];
		}
	}
	return *this;
}
template<typename t1>
matrix<t1>& matrix<t1>::operator = (matrix &&other)
{
	n=other.n;
	m=other.m;
	tab=other.tab;
	other.tab=nullptr;
	return *this;
}
template<typename t1>
void matrix<t1>::fill()
{
	rep(i,n)
		rep(j,m){
			tab[i][j]=rand()%10;
		}
}
template<typename t1>
void matrix<t1>::fill(t1 x)
{
	rep(i,n)
		rep(j,m){
			tab[i][j]=x;
		}
}
template<typename t1>
t1& matrix<t1>::at(ull x, ull y){ return tab[x][y];}
template<typename t1>
t1& matrix<t1>::operator [] (pair<ull,ull> pos){ return this->at(pos.first,pos.second);}
template<typename t1>
matrix<t1> matrix<t1>::sum(const matrix<t1> &b)
{
	matrix<t1> result(n,m);
	rep(i,n){
		rep(j,m){
			result.tab[i][j]=tab[i][j]+b.tab[i][j];
		}
	}
	return result;
}
template<typename t1>
matrix<t1> matrix<t1>::operator + (const matrix &other)
{
	return this->sum(other);
}
template<typename t1>
matrix<t1> matrix<t1>::multiply(t1 &b)
{
	matrix<t1> result(this->n,this->m);
	rep(i,this->n)
	{
		rep(j,this->m)
		{
			result[{i,j}]=this->tab[i][j]*b;
		}
	}
	return result;
}
template<typename t1>
matrix<t1> matrix<t1>::multiply(const matrix &b)
{
	if(this->m!=b.n)
	{
		cout<<"Macierze roznych rozmiarow"<<nl;
		return matrix(1,1);
	}
	matrix result(this->n,b.m);
	rep(i,result.n)
	{
		rep(j,result.m)
		{
			t1 result_sum=0;
			rep(k,this->m)
			{
				result_sum+=this->tab[i][k]*b.tab[k][j];
			}
			result[{i,j}]=result_sum;
		}
	}
	return result;
}
template<typename t1>
matrix<t1> matrix<t1>::operator * (t1 other)
{
	return this->multiply(other);
}
template<typename t1>
matrix<t1> matrix<t1>::operator * (const matrix &other)
{
	return this->multiply(other);
}
template<typename t1>
void matrix<t1>::trans()
{
	matrix result(this->m,this->n);
	rep(i,this->n)
	{
		rep(j,this->m)
		{
			result[{j,i}]=this->tab[i][j];
		}
	}
	matrix &temp = *this;
	*this = result;
	result = temp;
}
template<typename t2>
ostream& operator<< (ostream& stream, const matrix<t2> &m1)
{ 
	rep(i,m1.n){
		rep(j,m1.m){
			stream<<m1.tab[i][j]<<" ";
		}
		stream<<nl;
	}
	return stream;
}
template<typename t2>
istream& operator>> (istream& stream, matrix<t2> &m1)
{
	rep(i,m1.n){
		rep(j,m1.m){
			stream>>m1.tab[i][j];
		}
	}
	return stream;
}
template<typename t1>
pair<ull, ull> matrix<t1>::getDimensions()
{
	return {n,m};
}
template<typename t1>
matrix<t1> matrix<t1>::minor(ull x, ull y)
{
    matrix<t1> result(n-1,m-1);
    int isx=0, isy=0;
    rep(i,n){
	if(i==x) {isx++; continue;}
        rep(j,m){
		if(j==y) {isy++; continue;}
		if(i!=x&&j!=y) result[{i-isx, j-isy}] += tab[i][j];
	}
	isy=0;
    }
    return result;
}
template<typename t1>
t1 matrix<t1>::det()
{
    if(n!=m){ cout<<"Macierz nie jest kwadratowa"<<nl; return 0;}
    else if(n==1) {return tab[0][0];}
    else{
        t1 result=0;
        rep(i,n){
            result+=tab[0][i]*pow(-1,i)*this->minor(0,i).det();
        }
        return result;
    }
}
template<typename t1>
string matrix<t1>::getname()
{
	return name;
}
template<typename t1>
void matrix<t1>::setname(const string& _name)
{
	name = _name;
}
template<typename t1>
matrix<t1>& matrix<t1>::operator += (const matrix& other)
{
	*this=*this+other;
	return *this;
}
template<typename t1>
matrix<t1>& matrix<t1>::operator *= (t1 other)
{
	*this=*this*other;
	return *this;
}
template<typename t1>
matrix<t1>& matrix<t1>::operator *= (const matrix& other)
{
	*this=*this*other;
	return *this;
}
#endif //MATRIX_CPP
