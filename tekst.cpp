#include<iostream>
#include<string>

using namespace std;

int main()
{
	char nazwisko[20];
	cout<<"podaj nazwisko";
	cin>>nazwisko;
	cout<<"podales: "<<endl;
	cout<<"11 litera to: "<<nazwisko[10]<<endl;
	nazwisko[10]='Q';
	cout<<"11 litera to: "<<nazwisko[10]<<endl;
	
	string imie;
	cout<<"podaj imie: ";
	cin>>imie;
	cout<<"podales: "<<imie<<endl;
	int x = imie.length();
	cout<<"ostatnia litera to: "<<imie[x+1]<<endl;
	
	string imie_nazwisko;
	cout<<"podaj imie i nazwisko";
	cin.ignore();
	getline(cin, imie_nazwisko);
	cout<<"podales: "<<imie_nazwisko<<endl;
	
	string tekst = "ala ma kota";
	cout<<tekst<<endl;
	tekst += " i psa";
	cout<<tekst<<endl;
	cout<<"11 litera to: "<<tekst[10]<<endl;
	
	system("pause");
}
