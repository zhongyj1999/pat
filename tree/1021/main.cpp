#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int cnt, maxdepth = -1;
vector<int> ans, num, tree[10005];
bool vis[10005];

void dfs(int st, int depth, int flag){
    if(depth > maxdepth){
        maxdepth = depth;
        num[flag] = maxdepth;
    } else if(depth == maxdepth){
        num[flag] = maxdepth;
    }
    vis[st] = true;
    for(int i = 0; i < tree[st].size(); i++){
        if(vis[tree[st][i]] != true){
            //vis[tree[st][i]] = true;
            //printf("%d %d %d %d %d\n", flag, st, i, depth, tree[st][i]);
            dfs(tree[st][i], depth + 1, flag);
        }
    }
    //printf("%d %d\n", flag, num[flag]);
}

int main()
{
    int n;
    scanf("%d", &n);
    num.resize(n + 1);
    for(int i = 1; i < n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    for(int i = 1; i <= n; i++){
        if(vis[i] == false){
            dfs(i, 0, 0);
            cnt++;
        }
    }
    if(cnt > 1){
        printf("Error: %d components", cnt);
        return 0;
    }
    for(int i = 1; i <= n; i++){
        fill(vis, vis + 10005, false);
        dfs(i, 0, i);
    }
    for(int i = 1; i <= n; i++){
        if(num[i] == maxdepth){
            //printf("%d ", num[i]);
            ans.push_back(i);
        }
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++){
        printf("%d", ans[i]);
        if(i != ans.size() - 1) printf("\n");
    }
    return 0;
}
