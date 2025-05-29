#include<iostream>
#include<cstdlib>
#include <time.h>
#include <algorithm>

using namespace std;
int tab[1000];

void b(int tab[],int n);

int main()
{
	int tab, n;
	
	cin>>n;
	
    for(int i=0; i<n; i++)
    {
        tab[i]=(rand()%n +1);
        cout << " " << tab[i];
    }
	
	b(tab,n);
	
	cout<<endl;
	cout<<"Liczby posortowane: "<<endl;
	for(int i=0;i<n;i++)
    cout<<tab[i]<<" ";
}

void b(int tab[],int n)
{
	for(int i=0;i<n;i++)
		for(int j=1;j<n-i;j++) 
		if(tab[j-1]>tab[j])
			swap(tab[j-1], tab[j]);
}
