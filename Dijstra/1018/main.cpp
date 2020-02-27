#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
const int MAXV = 510;
const int INF = 1000000000;
int n, G[MAXV][MAXV];
int d[MAXV];
int W[MAXV];
bool vis[MAXV] = {false};
vector<int> pre[MAXV];
vector<int> path, tempPath;
int minBike = INF, needBike, backBike = INF;
int st = 0, ed;

void Dijkstra(int s){
    fill(d, d + MAXV, INF);
    d[s] = 0;
    for(int i = 0; i <= n; i++){
        int u = -1, MIN = INF;
        for(int j = 0; j <= n; j++){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 0; v <= n; v++){
            if(vis[v] == false && G[u][v] != INF){
                if(d[u] + G[u][v] < d[v]){
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                    //printf("%d1\n", u);
                }
                else if(d[u] + G[u][v] == d[v]){
                    pre[v].push_back(u);
                    //printf("%d2\n", u);
                }
            }
        }
    }
}

void DFS(int v){
    tempPath.push_back(v);
    //printf("%d", v);
    if(v == 0){
        int need = 0, backB = 0;
        for(int i = tempPath.size() - 1; i >= 0; i--){
            int id = tempPath[i];
            if(W[id] > 0){
                backB += W[id];
            }
            else{
                if(backB > (0 - W[id])){
                    backB += W[id];
                }
                else{
                    need += ((0 - W[id]) - backB);
                    backB = 0;
                }
            }
        }
        if(need < minBike){
            minBike = need;
            backBike = backB;
            path = tempPath;
        }
        else if(need == minBike && backB < backBike){
            backBike = backB;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    for(int i = 0; i < pre[v].size(); i++){
        //printf("%d" ,pre[v][i]);
        DFS(pre[v][i]);
    }
    tempPath.pop_back();

}

int main()
{
    int numRoad, u, v;
    fill(G[0], G[0] + MAXV * MAXV, INF);
    scanf("%d %d %d %d", &needBike, &n, &ed, &numRoad);
    for(int i = 1; i <= n; i++){
        scanf("%d", &W[i]);
        W[i] = W[i] - needBike / 2;
    }
    for(int i = 0; i < numRoad; i++){
        scanf("%d %d", &u, &v);
        scanf("%d", &G[u][v]);
        G[v][u] = G[u][v];
    }
    Dijkstra(0);
    DFS(ed);
    printf("%d 0", minBike);
    for(int i = path.size() - 2; i >= 0; i--){
        printf("->%d", path[i]);
    }
    printf(" %d", backBike);
    return 0;
}
