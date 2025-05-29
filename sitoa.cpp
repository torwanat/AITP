#include <iostream>
#include <math.h>

using namespace std;

/*Przepraszam za nie przes³anie zadania w terminie,
jednak z przyczyn niezale¿nych ode mnie nie mia³em 
dostêpu do komputera przez pó³ wczorajszego dnia,
dlatego nie mog³em wys³aæ zadania ju¿ wczoraj.
Stara³em siê je wys³aæ jak najwczeœniej jak mogê 
i mam nadziejê, ¿e panu to ma³e opóŸnienie nie przeszkadza.
Jeszcze raz przepraszam za k³opot*/

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
