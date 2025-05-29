#include <bits/stdc++.h>
using namespace std;

class Matrix
{
protected:
  double** a;
  int m, n;
  string name;
public:
  Matrix();
  void Create(int x, int y);
  Matrix(int x, int y, string N);
  Matrix(const Matrix& A);
  void Fill(int s);
  void Show() const;
  void Set(int i, int j, double r);
  double Get(int i, int j) const;
  int Get_m() const;
  int Get_n() const;
  void SetName(string N);
  string GetName() const;
  void Transpoz();
  ~Matrix();
};

Matrix Add(Matrix A, Matrix B);
Matrix ScalarMultiply(Matrix A, double k);
Matrix Multiply(Matrix A, Matrix B);

int main()
{
  srand(time(NULL));
  int a, b;
  cout << "Podaj wymiary macierzy do dodania: "; cin >> a >> b;
  Matrix A;
  A.Create(a, b);
  A.Fill(100);
  cout << "Macierz A:" << endl;
  A.Show();
  Matrix B;
  B.Create(a, b);
  B.Fill(100);
  cout << "Macierz B:" << endl;
  B.Show();
  cout << "Suma:" << endl;
  Matrix SUMA(Add(A, B));
  SUMA.Show();
  cout << "Podaj wymiary macierzy C: "; cin >> a >> b;
  Matrix C(a, b, "C");
  C.Fill(100);
  cout << "Macierz C:" << endl;
  C.Show();
  double l;
  cout << "Podaj skalar: "; cin >> l;
  cout << "Wynik mnozenia macierzy C przez skalar:" << endl;
  Matrix SCALAR(ScalarMultiply(C, l));
  SCALAR.Show();
  cout << "Iloczyn z mnozenia macierzy D i E:" << endl;
  Matrix D, E;
  D.Create(a, b);
  D.Fill(100);
  E.Create(b, a);
  E.Fill(100);
  Matrix ILOCZYN(Multiply(D, E));
  ILOCZYN.Show();
  return 0;
}

Matrix::Matrix()
{
  m = 0;
  n = 0;
}

void Matrix::Create(int x, int y)
{
  m = x;
  n = y;
  a = new double*[m];
  for (int i = 0; i < m; i++)
  {
    a[i] = new double[n];
    for (int o = 0; o < n; o++) a[i][o] = 0;
  }
}

Matrix::Matrix(int x, int y, string N)
{
  Create(x, y);
  name = N;
}

Matrix::Matrix(const Matrix& A)
{
  m = A.Get_m();
  n = A.Get_n();
  a = new double*[m];
  for (int i = 0; i < m; i++)
  {
    a[i] = new double[n];
    for (int o = 0; o < n; o++) a[i][o] = A.Get(i, o);
  }
}

void Matrix::Fill(int s)
{
  for (int i = 0; i < m; i++) for (int o = 0; o < n; o++) a[i][o] = rand() % s + 1;
}

void Matrix::Show() const
{
  for (int i = 0; i < m; i++)
  {
    for (int o = 0; o < n; o++) cout << a[i][o] << " ";
    cout << endl;
  }
}

void Matrix::Set(int i, int j, double r)
{
  a[i][j] = r;
}

double Matrix::Get(int i, int j) const
{
  return a[i][j];
}

int Matrix::Get_m() const
{
  return m;
}

int Matrix::Get_n() const
{
  return n;
}

void Matrix::SetName(string N)
{
  name = N;
}

string Matrix::GetName() const
{
  return name;
}

Matrix::~Matrix()
{
  for (int i = 0; i < m; i++) delete[] a[i];
  delete[] a;
}

Matrix Add(Matrix A, Matrix B)
{
  Matrix suma;
  suma.Create(A.Get_m(), A.Get_n());
  for (int i = 0; i < suma.Get_m(); i++) for (int o = 0; o < suma.Get_n(); o++) suma.Set(i, o, A.Get(i, o) + B.Get(i, o));
  return suma;
}

Matrix ScalarMultiply(Matrix A, double k)
{
  Matrix iloczyn;
  iloczyn.Create(A.Get_m(), A.Get_n());
  for (int i = 0; i < iloczyn.Get_m(); i++) for (int o = 0; o < iloczyn.Get_n(); o++) iloczyn.Set(i, o, A.Get(i, o) * k);
  return iloczyn;
}

Matrix Multiply(Matrix A, Matrix B)
{
  Matrix iloczyn;
  iloczyn.Create(A.Get_m(), B.Get_n());
  for (int i = 0; i < A.Get_m(); i++) for (int o = 0; o < B.Get_n(); o++) for (int j = 0; j < A.Get_n(); j++) iloczyn.Set(i, o, A.Get(i, j) * B.Get(j, o));
  return iloczyn;
}
