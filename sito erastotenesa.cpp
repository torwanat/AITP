#include<iostream>

using namespace std;

void sito(int tab[1000],int n)
{
	for (int i=2; i*i<=n; i++)
    {						
    if(!tab[i])			
	for (int j = i*i ; j<=n; j+=i) 
    tab[j] = 1;		
    }
}

int main()
{
	int n;
	int tab[1000];
	cout<<"Podaj zakres górny przedzia³u: ";
	cin>>n;
	for(int i=2; i<=n; i++){
		tab[i] = 0;
		}
	sito(tab, n); 
	cout<<"Kolejne liczby pierwsze z przedzia³u [2.."<<n<<"]: ";
	for(int i=2;i<=n;i++){
		if(!tab[i]){
			cout<<i<<" ";
		}
	}
    return 0;
}
