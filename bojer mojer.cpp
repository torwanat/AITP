#include<iostream>
#include<fstream>
#define nl "\n"
#define rep(a,b) for(int a=0; a<(b); ++a)

using namespace std;

void boyer_moore(istream &file, string &pattern, ostream &output)
{
        static int shift[128];
        rep(i,128) shift[i]=-1;
        rep(i,pattern.length()){ shift[pattern[i]] = i;}
        //for(int i=pattern.length()-1;i>=0;--i) shift[pattern[i]]=i;
        int line=0;
        string searched;
        int counter=0;
        while(getline(file,searched)){
                int linecounter=0;
                ++line;
                if(searched.length()<pattern.length()) continue;
                for(int i=0; i<=(searched.length()-pattern.length());)
                {
                        int j=pattern.length()-1;
                        while((j>-1)&&(pattern[j]==searched[i+j])) --j;
                        if(j==-1){
                        if(!linecounter) output<<"linia "<<line<<": ";
                        output<<i+1<<", ";
                        ++i;
                        ++linecounter;
                        }
                        else i+= max(1,j-shift[searched[i+j]]);
                        //cout<<searched<<nl;
                        //for(int k=0; k<i; ++k) cout<<" ";
                        //cout<<"^"<<nl;
                        //cout<<i<<" "<<j<<nl;
                }
                if(linecounter) output<<nl;
                counter+=linecounter;
                //cout<<nl;
        }
        cout<<counter;
}

int main()
{
        fstream file("tekst.txt");
        fstream output("wynik.txt");
        string key;
        getline(cin,key);
        boyer_moore(file,key,output);
        return 0;
}
