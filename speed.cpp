#include<iostream>
#include<cstdlib>
#include <time.h>
#include <algorithm>

using namespace std;

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

int main(){
	int l,r,n;
	l=0;
	cin>>n;
	r=n-1;
	int tab[n];
    for(int i=0; i<n; i++)
    {
        tab[i]=(rand()%n +1);
        cout << " " << tab[i];
    }
    s(tab,l,r);
    cout<<endl;
    cout<<"Elementy posortowane:"<<endl;
    for(int i=0; i<n; i++)
            cout<<tab[i]<<" ";	
}
