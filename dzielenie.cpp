#include<iostream>

using namespace std;

int main()
{
	int a,b,c;
	cout<<"Podaj a i b";
	cin>>a>>b;
	if(b==0) //if sposob 1
		cout<<"dzielenie przez 0\n";
	else{
			c=a/b;
            cout<<a<<"/"<<b<<"="<<c<<endl;
	}	
	
//albo
(b==0)? (cout<<"dzielenie przez 0\n"): //if sposob 2
        (	c=a/b, cout<<a<<"/"<<b<<"="<<c<<endl);
        	system("pause");
	return 0;
}
