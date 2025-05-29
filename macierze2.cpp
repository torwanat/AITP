#include <bits/stdc++.h>
using namespace std;

int main()
{
  srand(time(NULL));
  int nA, mA;
  cout << "Podaj wymiary macierzy A: "; cin >> mA >> nA;
  int** A = new int*[mA];
  for (int i = 0; i < mA; i++)
  {
    A[i] = new int[nA];
    for (int o = 0; o < nA; o++) A[i][o] = rand() % 100 + 1;
  }
  int nB, mB = nA;
  cout << "Podaj wymiar macierzy B: "; cin >> nB;
  int** B = new int*[mB];
  for (int i = 0; i < mB; i++)
  {
    B[i] = new int[nB];
    for (int o = 0; o < nB; o++) B[i][o] = rand() % 100 + 1;
  }
  int** C = new int*[mA];
  for (int i = 0; i < mA; i++)
  {
    C[i] = new int[nB];
    for (int o = 0; o < nB; o++) C[i][o] = 0;
  }
  for (int i = 0; i < mA; i++) for (int o = 0; o < nB; o++) for (int j = 0; j < nA; j++) C[i][o] += A[i][j] * B[j][o];
  for (int i = 0; i < mA; i++)
  {
    for (int o = 0; o < nB; o++) cout << C[i][o] << " ";
    cout << endl;
  }
  return 0;
}
