#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int n;
vector<int> in, level;

int cmp(int a, int b){
    return a < b;
}

void findroot(int st, int ed, int index){
    int root;
    if(st <= ed){
        int layer = log(ed - st + 1)/log(2);
        if(st == ed - 1) layer = 1;
        int num = pow(2, layer);
        int l = ed - st + 2 - 3 * pow(2, layer - 1);
        if(l <= 0){
            root = num + l + st - 1;
        }
        else{
            root = num + st - 1;
        }
        level[index] = in[root];
        findroot(st, root -1, 2 * index + 1);
        findroot(root + 1, ed, 2 * index + 2);
    }
}

int main()
{
    scanf("%d", &n);
    in.resize(n);
    level.resize(n);
    //int l = log(6)/log(2);
    //printf("%d\n", l);
    for(int i = 0; i < n; i++){
        scanf("%d", &in[i]);
    }
    sort(in.begin(), in.end(), cmp);
    findroot(0, n - 1, 0);
    printf("%d", level[0]);
    for(int i = 1; i < n; i++)
        printf(" %d", level[i]);
    return 0;
}
