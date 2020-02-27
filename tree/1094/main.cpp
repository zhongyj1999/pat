#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;
int n, m, flag, cnt = -1;
int num[105];
vector<int> tree[105];

void dfs(int st, int depth){
    num[depth]++;
    if(num[depth] > cnt){
        cnt = num[depth];
        flag = depth;
    }
    for(int i = 0; i < tree[st].size(); i++){
        dfs(tree[st][i], depth + 1);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    int k, c, t;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &k, &c);
        for(int j = 0; j < c; j++){
            scanf("%d", &t);
            tree[k].push_back(t);
            //printf("%d %d %d\n", k, j, t);
        }
    }
    dfs(1, 0);
    printf("%d %d", cnt, flag + 1);
    return 0;
}
