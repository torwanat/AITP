#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <time.h>
#include <ctime>
#include <fstream>
#include <string>


using namespace std;

ifstream in;
ofstream out;



float profile(int tab[],int n){
	float v;
	string t;
	t=" ";
	float ttab[n];
	clock_t t1;
	clock_t t2;
	for (int i=0;i<n;i++){
		t1=clock();
    	for(int i=0;i<n;i++)
    	{
        	for(int j=0;j<n-1;j++)
        	{
            	if( tab[j]>tab[j+1])
                 	swap(tab[j],tab[j+1]);
        	}
    	}
		t2=clock();
		ttab[i]=(float)(t2-t1)/CLOCKS_PER_SEC;
	}
	sort(ttab,ttab+n);
	v=0.0f;
	for(int i=1;i<n;i++){
		v=v+ttab[i];
	}
	v/=(float)(n-2.0f);
	out.open("data.txt",ios_base::app);
	if(out.good()){
		out<<v;
		out<<t;
		out.close();
	}else
	cout<<"Blad utworzenia pliku"<<endl;
	return v;
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<1000;i++){
	n++;
	int tab[n];
    for(int i=0; i<n; i++)
    {
        tab[i]=(rand()%n +1);
    }
    profile(tab,n);
    cout<<endl;
}
}
