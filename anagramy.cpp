#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

double anagram(string w1,string w2)
{
    if(w1.length()!=w2.length())
    {
        return false;
    }
    for(int i=0;i<w1.length()-1;i++)
    {
        for (int j=0;j<w2.length()-1;j++)
        {
            if(w1[j]>w1[j+1])
                swap(w1[j],w1[j+1]);
            if(w2[j]>w2[j+1])
                swap(w2[j],w2[j+1]);
        }
    }
    return w1==w2;
}

int main()
{
    string w1,w2;
    cout<<"Podaj wyraz pierwszy"<<endl;
    cin>>w1;
    cout<<"Podaj wyraz drugi"<<endl;
    cin>>w2;
    if(anagram(w1,w2))
    {
        cout<<"Wyrazy s¹ anagramami"<<endl;
    }
    else
    {
        cout<<"Wyrazy nie s¹ anagramami"<<endl;
    }
    return 0;
}
