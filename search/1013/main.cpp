#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
const int MAXN = 1010;
int G[MAXN][MAXN];
bool vis[MAXN];
int n, m, k;

void dfs(int node){
    vis[node] = true;
    for(int i = 1; i <= n; i++){
        if(vis[i] == false && G[node][i] == 1)
            dfs(i);
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    int u, v, city;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &u, &v);
        G[u][v] = G[v][u] = 1;
    }
    for(int i = 0; i < k; i++){
        scanf("%d", &city);
        fill(vis, vis + 1000, false);
        int cnt = 0;
        vis[city] = true;
        for(int j = 1; j <= n; j++){
            if(vis[j] == false){
                dfs(j);
                cnt++;
            }
        }
        printf("%d\n", cnt - 1);
    }
    return 0;
}
