#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector<int> znode[100];
int book[100], level[100];
int maxdepth = -1;


void bfs(){
    queue<int> q;
    q.push(1);
    level[1] = 0;
    while(!q.empty()){
        int index = q.front();
        q.pop();
        maxdepth = max(level[index], maxdepth);
        if(znode[index].size() == 0)
            book[level[index]]++;
        for(int i = 0; i < znode[index].size(); i++){
            q.push(znode[index][i]);
            level[znode[index][i]] = level[index] + 1;
        }
    }
}

int main()
{
    int n, m, node, childnum, child;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d", &node, &childnum);
        for(int j = 0; j < childnum; j++){
            scanf("%d", &child);
            znode[node].push_back(child);
        }
    }
    bfs();
    for(int i = 0; i <= maxdepth; i++){
        if(i == 0)
            printf("%d", book[i]);
        else
            printf(" %d", book[i]);
    }
    return 0;
}
