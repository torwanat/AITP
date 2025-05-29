#include<iostream>
#include <algorithm>
#include <cstdlib>
#include <time.h>

using namespace std;

void s(int tab[],int n)
{
    int t, j;
   
    for( int i=1;i<n;i++)
    {
        t=tab[i];
       
        for(j=i-1;j>=0 && tab[j]==0;j--)
             tab[j+1]=tab[j];
       
        tab[j+1]=t;
    }
}

int main(){
	int n,z;
	cin>>n;
	int tab[n];
//    for(int i=0; i<n; i++)
//    {
//        tab[i]=(rand()%n+1);
//        cout << " " << tab[i];
//    }
	for(int i=0;i<n;i++){
	cout<<"podaj "<<i+1<<" element: ";
	cin>>tab[i];
	}
    s(tab,n);
    cout<<endl;
    cout<<"Elementy posortowane:"<<endl;
    for(int i=0; i<n; i++)
            cout<<tab[i]<<" ";
}
