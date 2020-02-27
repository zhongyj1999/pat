#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
const int INF = 1000000000;
const int MAXV = 1020;
int n, m, k, Ds;
int G[MAXV][MAXV], d[MAXV];
bool vis[MAXV];
int ansid = -1;
double ansdis = -1, ansaver = INF;

void Dijkstra(){
    for(int index = n + 1; index <= n + m; index++){
        double mindis = INF, aver = 0;
        fill(d, d + MAXV, INF);
        fill(vis, vis + MAXV, false);
        d[index] = 0;
        for(int i = 0; i < n + m; i++){
            int u = -1, minn = INF;
            for(int j = 1; j <= n + m; j++){
                if(vis[j] == false && d[j] < minn){
                    u = j;
                    minn = d[j];
                }
            }
            if(u == -1) break;
            vis[u] = true;
            for(int v = 1; v <= n + m; v++){
                if(vis[v] == false && d[v] > d[u] + G[u][v])
                    d[v] = d[u] + G[u][v];
            }
        }
        for(int i = 1; i <= n; i++){
            if(d[i] > Ds){
                mindis = -1;
                break;
            }
            if(d[i] < mindis) mindis = d[i];
            //printf("%d %d %d\n", index, i, d[i]);
            aver += 1.0 * d[i];
        }
        if(mindis == -1) continue;
        aver = aver / n;
        if(mindis > ansdis){
            ansid = index;
            ansdis = mindis;
            ansaver = aver;
        } else if(mindis == ansdis && aver < ansaver){
            ansid = index;
            ansaver = aver;
        }
    }
    if(ansid == -1)
        printf("No Solution");
    else
        printf("G%d\n%.1f %.1f", ansid - n, ansdis, ansaver);
}

int main()
{
    scanf("%d %d %d %d", &n, &m, &k, &Ds);
    fill(G[0], G[0] + MAXV * MAXV, INF);
    for(int i = 0; i < k; i++){
        int tempCost;
        string s, t;
        int a, b;
        cin >> s >> t >> tempCost;
        if(s[0] == 'G'){
            s = s.substr(1);
            a = n + stoi(s);
        }
        else{
            a = stoi(s);
        }
        if(t[0] == 'G'){
            t = t.substr(1);
            b = n + stoi(t);
        }
        else{
            b = stoi(t);
        }
        G[a][b] = G[b][a] = tempCost;
        //printf("%d\n", tempCost);
    }
    Dijkstra();
    return 0;
}
