// Sortowanie B¹belkowe - Wersja nr 4
//--------------------------------------------------------
// (C)2012 mgr Jerzy Wa³aszek
// I Liceum Ogólnokszta³c¹ce
// im. K. Brodziñskiego
// w Tarnowie
//--------------------------------------------------------

#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

const int N = 20; // Liczebnoœæ zbioru.


int main()
{
  int d[N],i,p,pmin,pmax;
  
  srand((unsigned)time(NULL));

  for(i = 0; i < N; i++) d[i] = rand() % 100;
  for(i = 0; i < N; i++) cout << setw(4) << d[i];
  cout << endl;

// Sortujemy

  pmin = 0; pmax = N - 1;
  do
  {
    p = -1;
    for(i = pmin; i < pmax; i++)
      if(d[i] > d[i+1])
      {
        swap(d[i], d[i+1]);
        if(p < 0) pmin = i;
        p = i;
      }
    if(pmin) pmin--;
    pmax = p;
  } while(p >= 0);

// Wyœwietlamy wynik sortowania

  cout << "Po sortowaniu:\n\n";
  for(i = 0; i < N; i++) cout << setw(4) << d[i];
  cout << endl;
  return 0;
}
