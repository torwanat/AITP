#include <bits/stdc++.h>

using namespace std;

int main(){
	int m,n;
	cin>>m>>n;
	int tab[m][n];
	srand(time(NULL));
	for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(j>i)
                tab[i][j]=0;
            else
                tab[i][j]=rand()%100+1;
        }
    }
}
