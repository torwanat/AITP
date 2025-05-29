#include<iostream>
#include<cstdio>
#include<fstream>
#include<ctime>
#include<iostream>
#include <algorithm>
#include <cstdlib>
#include <time.h>
#include<string>
using namespace std;

fstream plik;
string sekwencja, kompresja;
int a;

void losowanieZapisywanie();
void kompresjaZapisywanie();

int main()
{
    losowanieZapisywanie();
    kompresjaZapisywanie();
    return 0;
}

void losowanieZapisywanie()
{
    plik.open("sekwencja.txt", ios::out);

    srand(time(NULL));

    a = rand() % 33 + 16;

    for (int i=0; i<a; i++) sekwencja += rand() % 2 + 48;

    plik<<sekwencja<<"\n";
}

void kompresjaZapisywanie()
{
    int b = 0;

    for (int i=0; i<a; i++)
    {
        b++;
        if (sekwencja[i] != sekwencja[i+1])
        {
            kompresja += to_string(b);
            kompresja += sekwencja[i];
            b = 0;
        }
    }
    plik<<kompresja;

    plik.close();
}

