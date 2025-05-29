#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

const int n=10;

int main()
{
	srand( time (NULL) );
	int liczby[n];
	
	cout<<sizeof(liczby)<<endl;
	
	liczby[0] = 5;
	liczby[1] = 8;
	
	cout<<liczby[0]<<endl;
	cout<<liczby[1]<<endl;
	
	for(int i=0;i<n;i++){
		cout<<"podaj "<<i+1<<" element: ";
		cin>>liczby[1];
	} 
	
	for(int i=0;i<n;i++)
	cout<<liczby[1]<<endl;
	
	//losowe
	
	int x=rand();
	cout<<x<<endl;
	
	cout<<"liczby losowe"<<endl;
	for(int i=0;i<n;i++)
	liczby[i]=rand()%300+1;
	
		for(int i=0;i<n;i++)
		cout<<liczby[i]<<endl;
		
		system("pause");
		return 0;
	
}
