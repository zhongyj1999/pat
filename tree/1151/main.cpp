#include <iostream>
#include <vector>
#include <map>

using namespace std;
map<int, int> mp;
vector<int> pre, in;

void lca(int stin, int edin, int preroot, int a, int b){
    if(stin > edin) return;
    int inroot = mp[pre[preroot]], ain = mp[a], bin = mp[b];
    if(ain < inroot && bin < inroot){
        lca(stin, inroot - 1, preroot + 1, a, b);
    } else if((ain < inroot && bin > inroot) || (ain > inroot && bin < inroot)){
        printf("LCA of %d and %d is %d.\n", a, b, in[inroot]);
    } else if(ain > inroot && bin > inroot){
        lca(inroot + 1, edin, preroot + 1 + (inroot - stin), a, b);
    } else if(ain == inroot){
        printf("%d is an ancestor of %d.\n", a, b);
    } else if(bin == inroot){
        printf("%d is an ancestor of %d.\n", b, a);
    }
}

int main(){
    int n, m, u, v;
    scanf("%d %d", &m, &n);
    pre.resize(n +1);
    in.resize(n + 1);
    for(int i = 1; i <= n; i++){
        scanf("%d", &in[i]);
        mp[in[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        scanf("%d", &pre[i]);
    }
    for(int i = 0; i < m; i++){
        scanf("%d %d", &u, &v);
        if(mp[u] == 0 && mp[v] == 0)
            printf("ERROR: %d and %d are not found.\n", u, v);
        else if(mp[u] == 0 || mp[v] == 0)
            printf("ERROR: %d is not found.\n", mp[u] == 0 ? u : v);
        else
            lca(1, n, 1, u, v);
    }
    return 0;
}
