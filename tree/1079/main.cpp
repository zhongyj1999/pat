#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;
double price, rate, total = 0.0;
struct node{
    double data;
    vector<int> child;
};
vector<node> v;


void dfs(int index, int depth){
    if(v[index].child.size() == 0){
        total += v[index].data * pow(1 + rate, depth);
        return;
    }
    for(int i = 0; i < v[index].child.size(); i++){
        dfs(v[index].child[i], depth + 1);
    }
}

int main()
{
    int n, k, c;
    scanf("%d %lf %lf", &n, &price, &rate);
    //printf("%d %f %f", n, price, rate);
    rate = rate / 100;
    v.resize(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &k);
        if(k == 0){
            scanf("%lf", &v[i].data);
        } else{
            for(int j = 0; j < k; j++){
                scanf("%d", &c);
                v[i].child.push_back(c);
            }
        }
    }
    dfs(0, 0);
    printf("%.1f", total * price);
    return 0;
}
/*
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
int n;
float price, rate, total;
struct node{
    int k;
    float pri;
    vector<int> child;
}tree[100005];

double pow(double x, int y){
    for(int i = y; i > 0; i--){
        x *=  (1.0 + 0.01 * rate);
    }
    return x;
}

void dfs(int st, int level){
    tree[st].pri = pow(price, level);
    if(tree[st].k != 0) total += tree[st].pri * tree[st].k;
    //printf("%d %f %d %f\n", st, tree[st].pri, tree[st].k, total);
    for(int i = 0; i < tree[st].child.size(); i++){
        dfs(tree[st].child[i], level + 1);
    }
}

int main()
{
    scanf("%d %f %f", &n, &price, &rate);
    //printf("%d %f %f", n, price, rate);
    int num, t;
    for(int i = 0; i < n; i++){
        scanf("%d", &num);
        if(num == 0){
            scanf("%d", &tree[i].k);
        }
        tree[i].child.resize(num);
        for(int j = 0; j < num; j++){
            scanf("%d", &t);
            tree[i].child[j] = t;
        }
    }
    dfs(0, 0);
    printf("%.1f", total);
    return 0;
}
*/
