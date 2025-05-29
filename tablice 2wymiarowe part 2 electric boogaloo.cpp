#include <bits/stdc++.h>

using namespace std;

int main(){
	int m,n;
	cin>>m>>n;
	int tab[m][n];
	srand(time(NULL));
	
	for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
                tab[i][j]=rand()%100+1;
        }
    }
    
    for(int i=0;i<m;i++){
        for(int j=0; j<n; j++)
            cout<<tab[i][j]<<" ";
        cout<<endl;
    }
    
    cout<<"__________________________________________________"<<endl;
    
    for(int i=0;i<m;i++){
    	for(int j=0;j<n;j++){
    		if(j>i){
    			tab[i][j]=0;
			}
		}
	}
	
	for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cout<<tab[i][j]<<" ";
        cout<<endl;
    }
    
    int s=0;
    for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			s+=tab[i][j];
		}
	}
	delete[] tab;	
	cout<<endl;
	cout<<s;
}
