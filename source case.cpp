#include<iostream>

using namespace std;

int main()
{
	int a;
	cout<<"podaj liczbe dnia"<<endl;
	cin>>a;
	
	switch(a)
	{
		case 1:
			cout<<"poniedzialek\n";
			break;
		case 2:
			cout<<"wtorek\n";
			break;
		case 3:
			cout<<"sroda\n";
			break;
		case 4:
			cout<<"czwartek\n";
			break;
		case 5:
			cout<<"piatek\n";
			break;
		case 6:
			cout<<"sobota\n";
			break;
		case 7:
			cout<<"niedziela\n";
			break;
		default:
			cout<<"nie ma takiego dnia\n";
	}
	
	system("pause");
	return 0;
}
