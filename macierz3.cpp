#include <iostream>

using namespace std;

main()
{
  int n, m, r, i, j, k, si;
  
  cin >> n >> m >> r; // odczytujemy wymiary macierzy

// tworzymy dynamicznie macierze A, B i C

  int * A = new int[n * m];
  int * B = new int[m * r];
  int * C = new int[n * r];
  
// odczytujemy zawartoœæ macierzy A

  for(i = 0; i < n; i++)
    for(j = 0; j < m; j++) cin >> A[i * m + j];
      
// odczytujemy zawartoœæ macierzy b

  for(i = 0; i < m; i++)
    for(j = 0; j < r; j++) cin >> B[i * r + j];

// Obliczamy iloczyn macierzy A i B w C

  for(i = 0; i < n; i++)
    for(j = 0; j < r; j++)
    {
      si = 0;
      for(k = 0; k < m; k++)
        si += A[i * m + k] * B[k * r + j];
      C[i * r + j] = si;
    }
    
// Wyprowadzamy wyniki

  cout << endl;
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < r; j++) cout << C[i * r + j] << " ";
    cout << endl;
  }    
}
