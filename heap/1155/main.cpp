#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int n, flag = 0;
vector<int> level, v;
vector<vector<int>> ans;

void traversal(int st){
    if(st * 2 + 2 < n){
        if(level[st * 2 + 2] < level[st]) flag++;
        else flag--;
        ans[st].push_back(st * 2 + 2);
        traversal(st * 2 + 2);
    }
    if(st * 2 + 1 < n){
        if(level[st * 2 + 1] < level[st]) flag++;
        else flag--;
        ans[st].push_back(st * 2 + 1);
        traversal(st * 2 + 1);
    }
}

void dfs(int st){
    v.push_back(st);
    if(ans[st].size() == 0){
        for(int i = 0; i < v.size(); i++){
            printf("%d", level[v[i]]);
            if(i != v.size() - 1) printf(" ");
            else printf("\n");
        }
        return ;
    }
    for(int i = 0; i < ans[st].size(); i++){
        dfs(ans[st][i]);
        v.pop_back();
    }
}

int main()
{
    scanf("%d", &n);
    level.resize(n);
    ans.resize(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &level[i]);
    traversal(0);
    dfs(0);
    if(flag == n - 1) printf("Max Heap");
    else if(flag == 1 - n) printf("Min Heap");
    else printf("Not Heap");
    return 0;
}
