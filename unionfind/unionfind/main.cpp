#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cctype>
#include <unordered_map>

using namespace std;
vector<int> fa, isRoot;
int course[1001] = {0};

int cmp1(int a, int b){
    return a > b;
}

int findFather(int x){
    int a = x;
    while(x != fa[x])
        x = fa[x];
    while(a != fa[a]){
        int z = a;
        a = fa[a];
        fa[z] = x;
    }
    return x;
}

void Union(int a, int b){
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB)
        fa[faA] = faB;
}

/*
int findFather(int x){
    if(x = fa[x])
        return x;
    else{
        f = findFather(fa[x]);
        fa[x] = f;
        return f;
    }
}
*/
void init(int x){
    for(int i = 1; i <= x; i++)
        fa[i] = i;
}

int main(){
    int n, k, a, cnt = 0;
    scanf("%d", &n);
    fa.resize(n+1);
    isRoot.resize(n+1);
    init(n);
    for(int i = 1; i <= n; i++){
        scanf("%d:", &k);
        for(int j = 0; j < k; j++){
            scanf("%d", &a);
            if(course[a] == 0)
                course[a] = i;
            Union(i, findFather(course[a]));
        }
    }
    for(int i = 1; i <= n; i++){
        isRoot[findFather(i)]++;
    }
    for(int i = 1; i <= n; i++){
        if(isRoot[i] != 0)
            cnt++;
    }
    sort(isRoot.begin(), isRoot.end(), cmp1);
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++){
        printf("%d", isRoot[i]);
        if(i != cnt-1)
            printf(" ");
    }
    return 0;
}

