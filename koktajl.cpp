#include<iostream>
#include <algorithm>
#include <cstdlib>
#include <time.h>

using namespace std;

void Sortowanie( int tab[], int size )
{
    int bottom = 0, top = size - 1;
    bool replace = true;
   
    while( replace )
    {
        replace = false;
       
        for( int i = bottom; i < top; i++ )
        {
            if( tab[ i ] > tab[ i + 1 ] )
            {
                swap( tab[ i ], tab[ i + 1 ] );
               
                replace = true;
            }
        }
       
       
        top--;
        for( int i = top; i > bottom; i-- )
        {
            if( tab[ i ] < tab[ i - 1 ] )
            {
                swap( tab[ i ], tab[ i - 1 ] );
               
                replace = true;
            }
        }
       
        bottom++;
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
    Sortowanie(tab,n);
    cout<<endl;
    cout<<"Elementy posortowane:"<<endl;
    for(int i=0; i<n; i++)
            cout<<tab[i]<<" ";
}
