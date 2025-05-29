#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <time.h>

using namespace std;

int tab[100000];

int sort(int n, int x)
{
    int p=0, k=n-1, d;
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

int main()
{
    int n, x, wynik;
    cout << "Podaj n: ";
    cin >> n;
    srand(time(NULL));
    for(int i=0; i<n; i++)
    {
        tab[i]=(rand()%n +1);
        cout << " " << tab[i];
    }
    cout << endl;
    cout << "Podaj x: ";
    cin >> x;
    sort(tab, tab+n);
    for(int i=0; i<n; i++)
        cout << " " << tab[i];
    cout << endl;
    wynik=sort(n,x);
    cout << wynik;


    return 0;
}
