#include<iostream>
#include<cmath>
using namespace std;

void sito(int n)
{
    bool tab[n+1];
for(int i=2; i<=n; i++) tab[i]=true;
for(int i=1;i<=sqrt(n);i++)
{
    if(tab[i]==true)
    {
for(int j=i*i; j<=n; j+=i) tab[j]=false;

    }
}
    cout << "Liczby pierwsze, nalezace do przedzialu [2," << n << "] to: " << endl;
    for(int i=2; i<=n; i++)
    {
        if(tab[i]==true) cout << i << endl;
    }

}

int main()
{
    int n;
    cin>>n;
    sito(n);

    system("pause");
    return 0;
}
