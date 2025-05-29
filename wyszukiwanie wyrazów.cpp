#include <bits/stdc++.h>

using namespace std;

int sprawdz(string ciag, string linia)
{
    bool wystapienie=false;
    int licznik=0;
    for(int i=0; i<linia.length(); i++)
    {
        for(int j=0; j<ciag.length(); j++)
        {
            if(tolower(ciag[j])!=tolower(linia[j+i]))
            {
                wystapienie = false;
                break;
            }
            else
                wystapienie = true;
        }
        if(wystapienie == true)
        {
            licznik++;
        }
    }
    return licznik;
}

int wystapienia(string ciag, string nazwa_pliku)
{
    ifstream plik;
    plik.open("Pan Tadeusz");

    int wystapienia = 0;
    string linia;
    if(plik.is_open())
    {
        while(getline(plik, linia))
        {
            wystapienia += sprawdz(ciag, linia);
        }
    }
    plik.close();
    return wystapienia;
}

int main()
{
    cout << wystapienia("Tadeusz", "Pan Tadeusz.txt");
    return 0;
}
