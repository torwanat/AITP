#include<iostream>

using namespace std;

int dziel(int a,int b);
int mno(int a,int b);
int dod(int a,int b);
int od(int a,int b);
int pt(int a, int b);
unsigned long long silnia(int a);
int sqrt(int a, int b);
int main(){

	int a,b;
	string c;
	cin>>a>>c>>b;
	if(c=="+"){
		cout<<dod(a,b);
	}
	if(c=="-"){
		cout<<od(a,b);
	}
	if(c=="*"){
		cout<<mno(a,b);
	}
	if(c=="/"){
		cout<<dziel(a,b);
	}
	if(c=="^"){
		cout<<pt(a,b);
	}
	if(c=="!"){
		cout<<silnia(a);
	}
	if(c=="|"){
		cout<<sqrt(a,b);
	}
}

int dod(int a,int b){
	return a+b;
}
od(int a,int b){
	return a-b;
}
mno(int a,int b){
	return a*b;
}
dziel(int a,int b){
	return a/b;
}
int pt(int a, int b){
	if(a==0 && b==0){
		return 0;
	}
	if(a!=0 && b==0){
		return 1;
	}
	if(b==1){
		return a;
	}
	if(a!=0 && b>1){
		return pt(a,b-1);
	}}
unsigned long long silnia(int a){
	if(a==0) return 1;
	else return a*silnia(a-1);
}
