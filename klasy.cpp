#include <bits/stdc++.h>
using namespace std;

class punkt{
	protected:
		double x;
		double y;
	public:
		punkt(void);
		punkt(double X, double Y);
		double get_x(void);
		double get_y(void);
		void set_x(double X);
		void set_y(double Y);
		double modul(void);
};

class kolo{
	private:
		double promien;
		punkt srodek;
	public:
		kolo();
		kolo(double r, double x, double y);
		kolo(double r, punkt p);
		double obwod();
		double pole();
		void set_r(double x);
		double get_r();
		void set_srodek(punkt p);
		punkt get_srodek();
};

int main(){
	double a,b;
	//punkt p1();
	cout<<"Podaj wspolrzedne punktu: \n";
	cin>>a>>b;
	punkt p1(a,b);
	//p1.set_x(a);
	//p1.set_y(b);
	cout<<"Punkt ("<<p1.get_x()<<","<<p1.get_y()<<") ";
	cout<<"jest oddalony od punktu (0,0) o "<<p1.modul()<<endl;
	
	punkt p2;
	p2.set_x(a);
	p2.set_y(b);
	
	//punkt + ko³o
	cout<<"Podaj promien kola 1: ";
	double pr;
	cin>>pr;
	cout<<"podaj wspolrzedne srodka kola 1: \n";
	double x,y;
	cin>>x>>y;
	
	kolo k1(pr,x,y);
	cout<<"Obwod kola 1 wynosi: ";
	cout<<k1.obwod()<<endl;
	
	cout<<"Podaj promien kola 2: ";
	cin>>pr;
	cout<<"Podaj wpsolrzedne srodka kola 2: ";
	cin>>x>>y;
	punkt sr(x,y);
	kolo k2(pr,sr);
	
	cout<<"Obwod kola 2 wynosi: ";
	cout<<k2.obwod()<<endl;
	cout<<"Pole kola 2 wynosi: ";
	cout<<k2.pole()<<endl;
	
	cout<<"Podaj nowy promieñ ko³a: ";
	cin>>pr;
	k2.set_r(pr);
	cout<<"Podaj nowe wspolrzedne srodka kola 2: \n";
	cin>>x>>y;
	sr.set_x(x);
	sr.set_y(y);
	
	cout<<"Promien wynosi: ";
	cout<<k2.get_r()<<endl;
	cout<<"Wpolrzedne srodka sa rowne: \n";
	cout<<"X: "<<sr.get_x()<<endl;
	cout<<"Y: "<<sr.get_y()<<endl;
	
	cout<<"Obwod kola 2 wynosi: ";
	cout<<k2.obwod()<<endl;
	cout<<"Pole kola 2 wynosi: ";
	cout<<k2.pole()<<endl;
	
	return 0;
}

double kolo::get_r(){
	return promien;
}

void kolo::set_r(double x){
	promien = x;
}

double kolo::obwod(){
	return 2*M_PI*promien;
}

double kolo::pole(){
	return M_PI*promien*promien;
}

kolo::kolo(double r, punkt p){
	promien = r;
	srodek.set_x(X);
	srodek.set_y(Y);
}

kolo::kolo(){
}

void kolo::set_srodek(punkt p){
	srodek = p;
}

punkt kolo::get_srodek(void){
	return srodek;
}

punkt::punkt(void){
}

punkt::punkt(double X, double Y){
	x = X;
	y = Y;
}

double punkt::get_x(){
	return x;
}

double punkt::get_y(){
	return y;
}

void punkt::set_y(double Y){
	y = Y;
}

void punkt::set_x(double X){
	x = X;
}

double punkt::modul(void){
	return sqrt((pow(0 - get_x(),2) + pow(0-get_y(),2)));
}
