#include<iostream>
#include<vector>
#include<fstream>
#include<cstdlib>
#include<string>

using namespace std;

int main(){
    fstream myfile;
    int a;
    vector<string> v;
    vector<string> t;
    string linia,miasto;
    bool znaleziono = false;
    myfile.open("miasta 852.txt", ios::in);
    while ( getline (myfile,linia) )
    {
      if (linia[0] == 1) {
        continue;
      }
      linia.erase(linia.begin(), linia.begin() + linia.find("PL") + 4);
      v.push_back(linia.substr(0, linia.find("  ")));
      t.push_back(linia.substr(linia.find("  ") + 2, (linia.find("  ") + 2) + linia.find("  ")));
    }
    for (const string& k : v) {
        cout << k << endl;
    }
    cout<<"a";
    for (const string& k : t) {
        cout << k << endl;
    }
 /*     while (!znaleziono) {
        cout<<"Wybierz miasto: "<<endl;
        cin.ignore(0);
        getline(cin,miasto);
        for (const string& k : v){
            if(miasto == k){
                cout<<"Znaleziono!";
                znaleziono = true;
                break;
            }
        }
        if(!znaleziono){
            cout<<"Nie znaleziono miasta o takiej nazwie :c"<<endl;
        }
    } */
    myfile.close();
}
