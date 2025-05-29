#include<iostream>
#include <algorithm>
#include <cstdlib>
#include <time.h>

using namespace std;

void s(int tab[], int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if( tab[j]>tab[j+1])
                 swap(tab[j],tab[j+1]);
           
        }
    }
}

int main(){
	int n;
	cin>>n;
	int tab[n];
    for(int i=0; i<n; i++)
    {
        tab[i]=(rand()%n +1);
        cout << " " << tab[i];
    }
    s(tab,n);
    cout<<endl;
    cout<<"Elementy posortowane:"<<endl;
    for(int i=0; i<n; i++)
            cout<<tab[i]<<" ";
}
