#include<iostream>
#include<fstream>

using namespace std;

int bajermajer(string p,string szukane,int shift[],int M,int N){
	if(M>N) return -1;
	
	int i=M-1;
	int j=M-1;
	
	while(j>0){
		while(szukane[j]!=p[i]){
			int x = shift[p[i]];
			if(M-j>x){
				i+=M-j;
			}else{
				i+=x;
			}
			
			if(i>N){
				return -1;
			}
			j=M-1;
		}
		j--;
		i--;
	}
	return i;
}

int main(){
	remove("wynik.txt");
	ifstream file("tekst.txt");
	ofstream output("wynik.txt");
	int M,N;
	string p;
	string szukane;
	getline(cin,szukane);
	p=szukane;
	M=szukane.length();
    int linia=0;
    int znaleziono=0;
    
	int shift[128];
	for(int i = 0; i < 128; i++) {
        shift[i] = M;
    }
    for(int i = M-1; i >= 0; i--) {
        if(shift[szukane[i]] < M) {
            continue;
        } else {
            shift[szukane[i]] = M-1-i;
        }
    }
    
    if(file){
    	while(getline(file,p)){
    		linia++;
    		N=p.length();
    		
    		int pozycja=bajermajer(p,szukane,shift,M,N);
    		if(pozycja>=0){
    			output<<"Linia "<<linia<<": "<<pozycja<<endl;
    			znaleziono++;
			}
		}
	}
	cout<<znaleziono;
	file.close();
	return 0;
	}

