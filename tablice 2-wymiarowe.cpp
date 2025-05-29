#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m, n;
    cout << "Podaj wymiary tablicy: ";
    cin >> m >> n;

    // Definiowanie tablicy dwuwymiarowej
    int **tab;
    tab = new int*[m];
    for(int i=0; i<m; i++)
        tab[i]=new int[n];

    // Wype³nianie tablicy dwuwymiarowej losowymi liczbami z zakresu 1-100
    srand(time(NULL));
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(j>i)
                tab[i][j]=0;
            else
                tab[i][j]=rand()%100+1;
        }
    }

    // Wypisywanie tablicy
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++)
            cout << tab[i][j] << " ";
        cout << endl;
    }

    // Sumowanie elementów tablicy i usuwanie tablicy
    int suma = 0;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++)
            suma += tab[i][j];
        delete[] tab[i];
    }
    delete[] tab;

    cout << "Suma elementow tablicy wynosi: " << suma;

    return 0;
}
