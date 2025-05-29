#include<iostream>
#include <algorithm>
#include <cstdlib>
#include <time.h>

using namespace std;

void s(int tab[], int n)
{
	int p;
  do
  {
    p = -1;
    for(int i = 0; i < n; i++)
      if(tab[i] > tab[i+1])
      {
        swap(tab[i], tab[i+1]);
        if(p < 0)i = i;
        p = i;
      }
    n = p;
  } while(p >= 0);
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
