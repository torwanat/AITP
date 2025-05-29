#include<iostream>
#include<time.h>
#include<windows.h>

using namespace std;

void sortowanie_babelkowe(int*tab,int n)
{
    for(int i; i<n; i++)
    {
        for(int j=n-1; j>=1; j--)
        {
            if(tab[j]>tab[j-1])
            {
                int bufor;
                bufor=tab[j-1];
                tab[j-1]=tab[j];
                tab[j]=bufor;
            }
        }
    }
}


void quicksort(int *tablica, int lewy, int prawy)
{
    int v=tablica[(lewy+prawy)/2];
    int i,j,x;
    i=lewy;
    j=prawy;
    do
    {
        while (tablica[i]<v) i++;
        while (tablica[j]>v) j--;
        if (i<=j)
        {
            x=tablica[i];
            tablica[i]=tablica[j];
            tablica[j]=x;
            i++;
            j--;
        }
    }
    while (i<=j);
    if (j>lewy) quicksort(tablica,lewy, j);
    if (i<prawy) quicksort(tablica, i, prawy);
}


int ile;
clock_t stop,start;
double czas;
int main()
{
    cout<<"Porownanie czasow sortowania v.1"<<endl;

    cout<<"Ile losowych liczb w tablicy: ";
    cin>>ile;
    int*tablica;
    tablica=new int [ile];

    int*tablica2;
    tablica2=new int [ile];

    srand(time(NULL));
    for(int i; i<ile; i++)
    {
        tablica[i]=rand()%10000+1;
        //cout<<""<<tablica[i]<<""<<;
    }
    /*  cout<<"Przed posortowaniem: "<<endl;
      for(int i; i<ile; i++)
      {
          tablica[i]=rand()%10000+1;
          cout<<tablica[i]<<" ";
      }
    */

    //przepisanie tablicy do tablicy2

 for(int i=0; i<ile; i++)
    {
        tablica2[i]=tablica[i];
    }


    cout<<"Sortuje babelkowo"<<endl;
    start=clock();
    sortowanie_babelkowe(tablica,ile);
    stop=clock();
    czas=(double)(stop-start)/ CLOCKS_PER_SEC;
    cout<<"Czas sortowania babelkowego wynosl: "<<czas<<"s"<<endl;


    cout<<"Sortuje szybko"<<endl;
    start=clock();
    quicksort(tablica2,0,ile-1);
    stop=clock();
    czas=(double)(stop-start)/ CLOCKS_PER_SEC;
    cout<<"Czas sortowania szybkiego wynosl: "<<czas<<"s"<<endl;

     /* cout<<"Po posortowaniu: "<<endl;
     for(int i; i<ile; i++)
     {
         cout<<tablica2[i]<<" ";
     }
     */

    delete[] tablica;
    delete[] tablica2;
    system("pause");
    return 0;
}


