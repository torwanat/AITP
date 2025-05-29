#include<cstdlib>
#include<iostream>
#include<vector>
#define MAXN 1000

using namespace std;

vector<int> cykl;
vector<int> kraw[MAXN + 1];
int n;
int m;

void eulerCheck(){
    for(int i = 0; i <= m; i++){
        if(sizeof(kraw[i]) % 2 != 0){
            cout << "Brak cyklu";
            break;
           }
           cout << i << " " << sizeof(kraw[i]) << endl;
    }

}

void go(int v){
    while(!kraw[v].empty()){
        int w = kraw[v].back();
        kraw[v].pop_back();
        go(w);
        cykl.push_back(v);
    }
}

int main(){
    cout << "Podaj kolejno wierzcholki i krawedzie:" << endl;
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b;
        cout << "Podaj a i b:" << endl;
        cin >> a >> b;
        kraw[a].push_back(b);
    }

    eulerCheck();

    /*go(1);
    for(int i = cykl.size() - 1; i >= 0; i--){
        cout << cykl[i] << ",";
    }*/
}
