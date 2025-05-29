#include<iostream>
#include <algorithm>
#include <cstdlib>
#include <time.h>
using namespace std;
void sortByChoice(int a, int tab)
{
    int minimum;

    //UPORZADKOWYWANIE PODANEJ PRZEZ UZYTKOWNIKA TABLICY

    for (int i = 0, j = 0, k; i < a; i++)
    {
        minimum = tab[i];
        j = i;
        while (j < a)
        {
            if (tab[j] < minimum)
            {
                minimum = tab[j];
                k = j;
            }
            j++;
        }
        if (tab[i] != minimum)
        {
            swap(tab[k], tab[i]);
        }
    }

    //WYPISYWANIE UPORZADKOWANEJ TABLICY

    for (int i = 0; i < a; i++)
    {
        cout << tab[i] << " ";
    }
}
int main(){
	int a;
	cin>>a;
	int tab[a];
	 srand(time(NULL));
    for(int i=0; i<a; i++)
    {
        tab[i]=(rand()%a +1);
        cout << " " << tab[i];
    }
	sortByChoice(a, tab[a]);
}
