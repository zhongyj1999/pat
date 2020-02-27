#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> father, isRoot;

int findFather(int x){
    int a = x;
    while(x != father[x])
        x = father[x];
    while(a != father[a]){
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void Union(int a, int b){
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB)
        father[faA] = faB;
}

void init(int x){
    for(int i = 1; i <= x; i++)
        father[i] = i;
}

int main()
{
    int n, k, t, treenum = 0;
    int birdsnum = 0;
    int Birds[10001]={0};
    scanf("%d", &n);
    father.resize(n + 1);
    isRoot.resize(n + 1);
    init(n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &k);
        for(int j = 0; j < k; j++){
            scanf("%d", &t);
            if(Birds[t] == 0){
                Birds[t] = i;
                birdsnum++;
            }
            Union(i, findFather(Birds[t]));
        }
    }
    for(int i = 1; i <= n; i++){
        isRoot[findFather(i)]++;
    }
    for(int i = 1; i <= n; i++){
        if(isRoot[i] != 0)
            treenum++;
    }
    printf("%d %d\n", treenum, birdsnum);
    int z, b, c;
    scanf("%d", &z);
    for(int i = 0; i < z; i++){
        scanf("%d %d", &b, &c);
        if(findFather(Birds[b]) == findFather(Birds[c]))
            printf("Yes");
        else
            printf("No");
        if(i != z - 1)
            printf("\n");
    }
    return 0;
}
