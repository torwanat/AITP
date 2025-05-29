#include <bits/stdc++.h>
using namespace std;

class cpunkt:public punkt
{
	protected:
		int R,G,B;
	public:
		cpunkt(double X, double Y, int _r, int _g, int _b);
		void setR(int r);
		int getR(void);
		void setG(int g);
		int getG(void);
		void setB(int b);
		int getB(void);
};

class B{
	public:
		int x;
		
		B(int a)
			:x(a)
		{ }
		
		void Bx(){
			cout<<"B: "<<x<<endl;
		}
};

class P
	: public B
{
public:
	int x;
	
	P(int a, int b)
		:B(a)
		,x(b)
		{}
		
	void Px(){
		cout<<"P: "<<x<<endl;
	}
};

int main(){
	P p(1,2);
	p.Bx();
	p.Px();
	cout<<"---"<<endl;
	p.x=0;
	p.Bx();
	p.Px();
	cout<<"---"<<endl;
	p.B::x=8;
	p.Bx();
	p.Px();
}
