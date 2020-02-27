#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
const int MAXV = 500;
const int INF = 1000000000;
int n, G[MAXV][MAXV];
int d[MAXV];
int W[MAXV];
bool vis[MAXV] = {false};
vector<int> pre[MAXV];
vector<int> path, tempPath;
int maxWeight = 0, numPath = 0;
int st, ed;

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
    if(v == st){
        tempPath.push_back(v);
        numPath++;
        int weight = 0;
        for(int i = tempPath.size() - 1; i >= 0; i--){
            int id = tempPath[i];
            weight += W[id];
        }
        if(weight > maxWeight){
            maxWeight = weight;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for(int i = 0; i < pre[v].size(); i++){
        DFS(pre[v][i]);
    }
    tempPath.pop_back();
}

int main()
{
    int numRoad, u, v;
    fill(G[0], G[0] + MAXV * MAXV, INF);
    scanf("%d %d %d %d", &n, &numRoad, &st, &ed);
    for(int i = 0; i < n; i++){
        scanf("%d", &W[i]);
    }
    for(int i = 0; i < numRoad; i++){
        scanf("%d %d", &u, &v);
        scanf("%d", &G[u][v]);
        G[v][u] = G[u][v];
    }
    Dijkstra(st);
    DFS(ed);
    printf("%d %d\n", numPath, maxWeight);
    return 0;
}
