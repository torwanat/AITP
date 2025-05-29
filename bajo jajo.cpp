#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

int main(){
	string wzor, tekst;
	int M,N;
	M = wzor.length();
	N = tekst.length();
	int shift[128];
	
	cin>>tekst>>wzor;
	
	for(int i=0;i<128;i++){
		shift[i]=M;
	}
	
	for(int i=M-1;i>=0;i--){
		if(shift[wzor[i]]<M){
			continue;
		}else{
			shift[wzor[i]]=M-1-i;
		}
	}
	if(M>N){
		cout<<"Nie znaleziono";
		exit(0);
	}
	for(int i=M-1, j=M-1;j>0;j--,i--){
		while(i!=j){
			
			if(M-j>x){
				i +=M-j;
			}else{
				i += x;
			}
			if(i>N){
				cout<<"Nie znaleziono";
				exit(0);
			}
		}
	}
}
