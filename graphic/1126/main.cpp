#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> v;
vector<int> vis;
int num = 0;

void dfs(int index){
    vis[index] = true;
    num++;
    for(int i = 0; i < v[index].size(); i++)
        if(vis[v[index][i]] == false)
            dfs(v[index][i]);
}

int main()
{
    int n, m, cnt = 0;
    scanf("%d %d", &n, &m);
    v.resize(n + 1);
    vis.resize(n + 1);
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        if(v[i].size() % 2 == 0) cnt++;
        printf("%d", v[i].size());
        if(i == n) printf("\n");
        else printf(" ");
    }
    dfs(1);
    if(cnt == n && num == n) printf("Eulerian");
    else if(cnt == n - 2 && num == n) printf("Semi-Eulerian");
    else printf("Non-Eulerian");
    return 0;
}
