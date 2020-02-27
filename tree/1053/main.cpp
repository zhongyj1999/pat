#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;
const int MAXV = 105;
int n, m, w, total = 0, cnt = 0;
int have[MAXV];
vector<int> node[MAXV], ans[MAXV], tempans, W;

bool cmp1(int a, int b){
    return a > b;
}

void DFS(int r){
    if(total + W[r] <= w){
        total += W[r];
        tempans.push_back(W[r]);
        for(int i = 0; i < node[r].size(); i++){
            DFS(node[r][i]);
        }
        //printf("%d\n", r);
        if(total == w && have[r] == -1){
            ans[cnt++]= tempans;
            //printf("%d\n", cnt);
            //tempans.pop_back();
        }
        total -= W[r];
        tempans.pop_back();
    }
}

int main()
{
    int root = 0;
    fill(have, have + MAXV, -1);
    scanf("%d %d %d", &n, &m, &w);
    W.resize(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &W[i]);
        //printf("%d %d\n", i, W[i]);
    }
    for(int i = 0; i < m; i++){
        int id, num;
        scanf("%d %d", &id, &num);
        have[id] = 1;
        //printf("%d %d\n", id, have[id]);
        node[id].resize(num);
        for(int j = 0; j < num; j++){
            scanf("%d", &node[id][j]);
            //printf("%d %d %d\n", id, num, temp);
            //node[id].push_back(temp);
        }
        for(int a = 0; a < num; a++){
            for(int b = 0; b < num; b++){
                if(W[node[id][a]] < W[node[id][b]]){
                    int temp = node[id][b];
                    node[id][b] = node[id][a];
                    node[id][a] = temp;
                    //printf("%d %d\n", W[node[id][a]], W[node[id][b]]);
                }
            }
        }
    }
    DFS(root);
    for(int i = cnt - 1; i >= 0; i--){
        for(int j = 0; j < ans[i].size(); j++){
            if(j == 0) printf("%d", ans[i][j]);
            else
                printf(" %d", ans[i][j]);
        }
        if(i != 0) printf("\n");
    }
    return 0;
}
