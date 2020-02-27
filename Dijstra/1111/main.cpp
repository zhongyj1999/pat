#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;
const int INF = 1000000000;
const int MAXV = 510;
int n, m, st, ed, mintime = INF, minnode = INF;
int length[MAXV][MAXV], timet[MAXV][MAXV];
int dl[MAXV], dt[MAXV];
bool vis[MAXV];
vector<int> prel[MAXV], pret[MAXV], pathl, patht, tempPathl, tempPatht;

void LDijkstra(int s){
    fill(dl, dl + MAXV, INF);
    fill(vis, vis + MAXV, false);
    dl[s] = 0;
    for(int i = 0; i < n; i++){
        int u = -1, MIN= INF;
        for(int j = 0; j < n; j++){
            if(vis[j] == false && dl[j] < MIN){
                u = j;
                MIN= dl[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 0; v < n; v++){
            if(vis[v] == false && length[u][v] != INF){
                if(dl[u] + length[u][v] < dl[v]){
                    dl[v] = dl[u] + length[u][v];
                    prel[v].clear();
                    prel[v].push_back(u);
                }
                else if(dl[u] + length[u][v] == dl[v]){
                    prel[v].push_back(u);
                }
            }
        }
    }
}


void TDijkstra(int s){
    fill(dt, dt + MAXV, INF);
    fill(vis, vis + MAXV, false);
    dt[s] = 0;
    for(int i = 0; i < n; i++){
        int u = -1, MIN= INF;
        for(int j = 0; j < n; j++){
            if(vis[j] == false && dt[j] < MIN){
                u = j;
                MIN= dt[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 0; v < n; v++){
            if(vis[v] == false && timet[u][v] != INF){
                if(dt[u] + timet[u][v] < dt[v]){
                    dt[v] = dt[u] + timet[u][v];
                    pret[v].clear();
                    pret[v].push_back(u);
                }
                else if(dt[u] + timet[u][v] == dt[v]){
                    pret[v].push_back(u);
                }
            }
        }
    }
}

void LDFS(int v){
    tempPathl.push_back(v);
    if(v == st){
        int temptime = 0;
        for(int i = tempPathl.size() - 1; i > 0; i--){
            int id = tempPathl[i], nextid = tempPathl[i - 1];
            temptime += timet[id][nextid];
        }
        if(temptime < mintime){
            mintime = temptime;
            pathl = tempPathl;
        }
        tempPathl.pop_back();
        return;
    }
    for(int i = 0; i < prel[v].size(); i++){
        LDFS(prel[v][i]);
    }
    tempPathl.pop_back();
}

void TDFS(int v){
    tempPatht.push_back(v);
    if(v == st){
        int tempnode = 0;
        tempnode = tempPatht.size();
        if(tempnode < minnode){
            minnode = tempnode;
            patht = tempPatht;
        }
        tempPatht.pop_back();
        return;
    }
    for(int i = 0; i < pret[v].size(); i++){
        TDFS(pret[v][i]);
    }
    tempPatht.pop_back();
}

int main()
{
    scanf("%d %d", &n, &m);
    fill(timet[0], timet[0] + MAXV * MAXV, INF);
    fill(length[0], length[0] + MAXV * MAXV, INF);
    int a, b, ow, l, t;
    for(int i = 0; i < m; i++){
        scanf("%d %d %d %d %d", &a, &b, &ow, &l, &t);
        length[a][b] = l;
        timet[a][b] = t;
        if(ow == 0){
            length[b][a] = l;
            timet[b][a] = t;
        }
    }
    scanf("%d %d", &st, &ed);
    LDijkstra(st);
    TDijkstra(st);
    LDFS(ed);
    TDFS(ed);
    if(pathl == patht){
        printf("Distance = %d; Time = %d: %d", dl[ed], dt[ed], st);
        for(int i = pathl.size() - 2; i >= 0; i--){
            printf(" -> %d", pathl[i]);
        }
        return 0;
    }
    printf("Distance = %d: %d", dl[ed], st);
    for(int i = pathl.size() - 2; i >= 0; i--){
        printf(" -> %d", pathl[i]);
    }
    printf("\nTime = %d: %d", dt[ed], st);
    for(int i = patht.size() - 2; i >= 0; i--){
        printf(" -> %d", patht[i]);
    }
    return 0;
}
