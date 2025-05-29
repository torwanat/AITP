#include<iostream>

using namespace std;

int main()
{
	int c,m,w,s,a;
	m=0;
	a=0;
	w=0;
	s=0;
	cin>>c;
	for(int i=1;i<=c;i++){
		m++;
		if(c%m==0){
			if(a<1 && m!=1){
				w=m;
				a++;
			}
			if(m>s && m!=c){
				s=m;
			}
			}
	}
	cout<<w<<" "<<s;
}
