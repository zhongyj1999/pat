#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;
double price, rate, tempprice, maxprice = 0.0;
int cnt;
vector<int> tree[100000];

void dfs(int st, int depth){
    if(tree[st].size() == 0){
        tempprice = price * pow((1 + rate), depth);
        if(tempprice > maxprice){
            maxprice = tempprice;
            cnt = 1;
        } else if(tempprice == maxprice){
            cnt++;
        }
        return;
    }
    for(int i = 0;  i < tree[st].size(); i++){
        dfs(tree[st][i], depth + 1);
    }

}

int main()
{
    int n, k, root;
    //tree.resize(n);
    scanf("%d %lf %lf", &n, &price, &rate);
    rate = rate / 100;
    for(int i = 0; i < n; i++){
        scanf("%d", &k);
        if(k == -1)
            root = i;
        else
            tree[k].push_back(i);
    }
    dfs(root, 0);
    printf("%.2f %d", maxprice, cnt);
    return 0;
}
