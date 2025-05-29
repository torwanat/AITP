#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <time.h>

using namespace std;
int m;

int sort( int n, int x);

int main()
{
	int n,x,w,t,s,z;
	t=0;
	s=1000;
	cin>>n;
	int tab[n-1];
    srand(time(NULL));
    for(int i=0; i<n; i++)
    {
        tab[i]=(rand()%n +1);
        cout << " " << tab[i];
    }
    for(int i=0; i<n; i++)
    {
	if(tab[i]>t){
		t=tab[i];
	}
	if(tab[i]<s){
		s=tab[i];
	}
    }
    m=(t-s)+1;
    sort(tab,tab+n);
    cout<<" "<<endl;
    for(int i=0; i<n; i++)
    cout << " " << tab[i];
}
int sort(int n, int x)
{
    int p=0, k=n-1, d;
    int tab[m];
    do
    {
        d=(p+k)/2;
        if(tab[d]==x)
            return d;
        else
        {
            if(tab[d]>x)
                k=d-1;
            else
                p=d+1;
        }
    } while(p<=k);
    return -1;
}
