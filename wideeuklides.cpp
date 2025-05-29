#include<iostream>

using namespace std;

int NWD(int a, int b)
{
    if(b == 0) return a;
	else return NWD(b,a%b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    if(NWD(a, b) != 1){
        cout << "Liczby musz¹ byæ wzglêdnie pierwsze!" << endl;
        return 0;
    }

}
