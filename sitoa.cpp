#include <iostream>
#include <math.h>

using namespace std;

/*Przepraszam za nie przes�anie zadania w terminie,
jednak z przyczyn niezale�nych ode mnie nie mia�em 
dost�pu do komputera przez p� wczorajszego dnia,
dlatego nie mog�em wys�a� zadania ju� wczoraj.
Stara�em si� je wys�a� jak najwcze�niej jak mog� 
i mam nadziej�, �e panu to ma�e op�nienie nie przeszkadza.
Jeszcze raz przepraszam za k�opot*/

int main()
{
    int n = 102;
    string s1, s2;
    int z[26];
    int j = 2;
    int w1 = 1;
    int w2 = 1;
    bool sito [n];

    for(int i = 0; i < n; i++)
    {
        sito[i] = true;
    }

    for(int i = 2; i < n; i++)
    {
        if(sito [i] == true)
        {
            int j = i + i;

            while(j < n)
            {
                sito [j] = false;
                j += i;
            }
        }
    }

    for(int i = 0; i < 26; i++)
    {
        while(sito [j] == false)
        {
            j ++;
        }

        z [i] = j;
        j ++;
    }
    
    cout<<"Podaj wyrazy do sprawdzenia: "<<endl;
    cin>>s1>>s2;

    int d1 = s1.length();
    int d2 = s2.length();

    if (d1 != d2)
    {
        cout<<"Te wyrazy to nie anagramy.";
        exit(0);
    }

    for(int i = 0; i < d1; i++)
    {
        w1*= z [(int)(s1[i]) - 97];
        w2*= z [(int)(s2[i]) - 97];
    }

    if(w1 == w2)
    {
        cout<<"Te wyrazy to anagramy!";
    }
    else
    {
        cout<<"Te wyrazy to nie anagramy.";
    }

    return 0;
}
