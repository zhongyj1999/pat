#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;
int n, cnt = 1, lowdepth = 1000000;
double price, rate;
vector<int> tree[100010];

void dfs(int st, int depth){
    if(lowdepth < depth) return;
    if(tree[st].size() == 0){
        if(depth == lowdepth){
            cnt++;
        } else if(depth < lowdepth){
            lowdepth = depth;
            cnt = 1;
        }
    }
    for(int i = 0; i < tree[st].size(); i++){
        //printf("%d %d %d\n", st, i, tree[st][i]);
        dfs(tree[st][i], depth + 1);
    }
}

int main()
{
    scanf("%d %lf %lf", &n, &price, &rate);
    rate = rate / 100;
    //printf("%d %f %f", n, price, rate);
    int k, c;
    for(int i = 0; i < n; i++){
        scanf("%d", &k);
        for(int j = 0; j < k; j++){
            scanf("%d", &c);
            tree[i].push_back(c);
            //printf("\n%d %d %d\n", i, j, tree[i][j]);
        }
    }
    dfs(0, 0);
    printf("%.4f %d", price * pow(1 + rate, lowdepth), cnt);
    return 0;
}
