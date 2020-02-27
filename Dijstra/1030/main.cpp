#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;
const int MAXV = 510;
const int INF = 1000000000;
int n, m, st, ed;
int G[MAXV][MAXV], d[MAXV], cost[MAXV][MAXV];
vector<int> pre[MAXV], path, tempPath;
bool vis[MAXV] = {false};
int mincost = INF;

void Dijkstra(int s){
    fill(d, d + MAXV, INF);
    d[s] = 0;
    for(int i = 0; i < n; i++){
        int u = -1, MIN = INF;
        for(int j = 0; j < n; j++){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 0; v < n; v++){
            if(vis[v] == false && G[u][v] != INF){
                if(d[u] + G[u][v] < d[v]){
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if(d[u] + G[u][v] == d[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void DFS(int v){
    tempPath.push_back(v);
    if(v == st){
        int tempcost = 0;
        for(int i = tempPath.size() - 1; i > 0; i--){
            int id = tempPath[i], idnext = tempPath[i - 1];
            tempcost += cost[id][idnext];
        }
        if(tempcost < mincost){
            mincost = tempcost;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    for(int i = 0; i < pre[v].size(); i++){
        DFS(pre[v][i]);
    }
    tempPath.pop_back();
}

int main()
{
    scanf("%d %d %d %d", &n, &m, &st, &ed);
    int u, v;
    fill(G[0], G[0] + MAXV * MAXV, INF);
    for(int i = 0; i < m; i++){
        scanf("%d %d", &u, &v);
        scanf("%d %d", &G[u][v], &cost[u][v]);
        G[v][u] = G[u][v];
        cost[v][u] = cost[u][v];
    }
    Dijkstra(st);
    DFS(ed);
    for(int i = path.size() - 1; i >= 0; i--){
        printf("%d ", path[i]);
    }
    printf("%d %d\n", d[ed], mincost);
    return 0;
}
