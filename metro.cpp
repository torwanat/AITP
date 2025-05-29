#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
#define MAXN 10000
#define INF 1000000000

using namespace std;

int n, m;
vector<int> kraw[MAXN + 1];
vector<int> waga[MAXN + 1];


void Djikstra(int src){
    int dis[MAXN + 1];
    int ojc[MAXN + 1];
    int vis[MAXN + 1];
    int largest = -1;

        for(int i = 1; i <= n; i++){
            vis[i] = false;
        }
        for(int i = 1; i <= n; i++){
            dis[i] = INF;
        }
        dis[src] = 0;

        while(true){
            int v = src;
            for(int i = 1; i <= n; i++){
                if(!vis[i]){
                    v = i;
                }
            }
            for(int i = 1; i <= n; i++){
                if(!vis[i] && dis[i] < dis[v]){
                    v = i;
                }
            }
            if(vis[v] || dis[v] == INF){
                break;
            }
            vis[v]=true;
            for(int i = 0; i < kraw[v].size(); i++){
                int w = kraw[v][i];
                int k = waga[v][i];
                if(dis[v] + k < dis[w]){
                    dis[w] = dis[v] + k;
                    ojc[w] = v;
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(dis[i] > largest){
                largest = dis[i];
            }
            cout << dis[i] << endl;
        }
}

int main(){
    cin >> n;
    m = n - 1;

    while(m--){
        int a, b, c;
        cin >> a >> b;
        c = 1;
        kraw[a].push_back(b);
        waga[a].push_back(c);
    }

    for(int i = 1; i <= n; i++){
        Djikstra(i);
    }

        /*for(int i = 1; i <= n; i++){
            vis[i] = false;
        }
        for(int i = 1; i <= n; i++){
            dis[i] = INF;
        }
        dis[2] = 0;

        while(true){
            int v = 2;
            for(int i = 1; i <= n; i++){
                if(!vis[i]){
                    v = i;
                }
            }
            for(int i = 1; i <= n; i++){
                if(!vis[i] && dis[i] < dis[v]){
                    v = i;
                }
            }
            if(vis[v] || dis[v] == INF){
                break;
            }
            vis[v]=true;
            for(int i = 0; i < kraw[v].size(); i++){
                int w = kraw[v][i];
                int k = waga[v][i];
                if(dis[v] + k < dis[w]){
                    dis[w] = dis[v] + k;
                    ojc[w] = v;
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(dis[i] > largest){
                largest = dis[i];
            }
            cout << dis[i] << endl;
        }*/
}
