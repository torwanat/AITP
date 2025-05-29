#include<iostream>

using namespace std;

int main()
{
	int i=0;
	//inkrementacja
	cout<<i++<<endl;//to samo co i=i+1 post inkrementacja
	cout<<i<<endl;
	
	cout<<++i<<endl;//to samo co i=i+1 pre inkrementacja
	cout<<i<<endl;
	
	//dekrementacja
	//   i-- to samo i=i-1 post dekrementacja
	//   --i to samo i=i-1 pre dekrementacja
	
	cout<<(i+=5)<<endl;// to samo co i=i+5
	cout<<(i-=2)<<endl;//to samo co i=i-2
	cout<<(i*=3)<<endl;//to samo co i=i*3
	cout<<(i%=2)<<endl;//to samo co i=i%2
	cout<<(i/=2)<<endl;//to samo co i=i/2
	
	system("pause"); 
	
}
