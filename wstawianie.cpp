#include<iostream>
#include <algorithm>
#include <cstdlib>
#include <time.h>
using namespace std;

void sortowanie_przez_wstawianie(int n, int *tab)
{
    int pom, j;
    for(int i=1; i<n; i++)
    {
    pom = tab[i]; 
    j = i-1;        
    while(j>=0 && tab[j]>pom) 
    {
    tab[j+1] = tab[j]; 
    --j;
    }
    tab[j+1] = pom; }     
}

int main()
{
    int n, *tab;
    cout<<"Podaj wielkosc zbioru: ";
    cin>>n;
    
    tab = new int [n];
    
    for(int i=0; i<n; i++)
    {
        tab[i]=(rand()%n +1);
        cout << " " << tab[i];
    }
    
    sortowanie_przez_wstawianie(n, tab);
    cout<<endl;
    cout<<"Elementy posortowane:"<<endl;
    for(int i=0; i<n; i++)
            cout<<tab[i]<<" ";

    return 0;    
}

