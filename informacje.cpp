#include<iostream>

using namespace std;

int main()
{
	int i=0;
	for(int i=1; i<=10; i++){
		cout<<"i=";
		cout<<i<<endl;
		}
		cout<<"poza petla i"<<i<<endl;
		cout<<"preinkrementacja"<<endl;
		for(int i=1; i<=10; i++)
		cout<<"i="<<i<<endl;
		
	    cout<<"postinkrementacja"<<endl;
	    for( int i=1 ; i<=10;i++)
	    cout<<"i="<<i++<<endl;
	    
	    cout<<"alternatywna petla for: bez warunkow ()";
	    int j=1;
	    for( ; ; ) {
	    	if(j<=10)
	    	cout<<"j"<<j<<endl;
	    	else
	    	break;
	    	j++;
	    	
		}
		cout<<"po zakonczeniu petli j="<<j<<endl;
		return 0;
}
