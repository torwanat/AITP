#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <time.h>
#include <ctime>
#include <fstream>
#include <string>


using namespace std;

ifstream in;
ofstream out;

void s(int tab[],int l,int r)
{
    int i=l;
    int j=r;
    int x=tab[(l+r)/2];
    do
    {
        while(tab[i]<x)
             i++;
       
        while(tab[j]>x)
             j--;
       
        if(i<=j)
        {
            swap(tab[i],tab[j]);
           
            i++;
            j--;
        }
    } while(i<=j);
   
    if(l<j) s(tab,l,j);
   
    if(r>i) s(tab,i,r);
   
}

float profile(int tab[],int n){
	float v;
	int l,r;
	string t;
	t=" ";
	l=0;
	r=n-1;
	float ttab[n];
	clock_t t1;
	clock_t t2;
	for (int u=0;u<n;u++){
		t1=clock();
    int i=l;
    int j=r;
    int x=tab[(l+r)/2];
    do
    {
        while(tab[i]<x)
             i++;
       
        while(tab[j]>x)
             j--;
       
        if(i<=j)
        {
            swap(tab[i],tab[j]);
           
            i++;
            j--;
        }
    } while(i<=j);
   
    if(l<j) s(tab,l,j);
   
    if(r>i) s(tab,i,r);
		t2=clock();
		ttab[i]=(float)(t2-t1)/CLOCKS_PER_SEC;
	}
	sort(ttab,ttab+n);
	v=0.0f;
	for(int i=1;i<n;i++){
		v=v+ttab[i];
	}
	v/=(float)(n-2.0f);
	out.open("data2.txt",ios_base::app);
	if(out.good()){
		out<<v;
		out<<t;
		out.close();
	}else
	cout<<"Blad utworzenia pliku"<<endl;
	return v;
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<1000;i++){
	n++;
	int tab[n];
    for(int i=0; i<n; i++)
    {
        tab[i]=(rand()%n +1);
    }
    profile(tab,n);
    cout<<endl;
}
}
