#include <iostream>
#include <vector>
#include <map>

using namespace std;
map<int, bool> mp;

int main(){
    int n, m, u, v, a;
    scanf("%d %d", &m, &n);
    vector<int> pre(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &pre[i]);
        mp[pre[i]] = true;
    }
    for(int i = 0; i < m; i++){
        scanf("%d %d", &u, &v);
        for(int j = 0; j < n; j++){
            a = pre[j];
            if((a >= u && a <= v) || (a <= u && a >= v)) break;
        }
        if(mp[u] == false && mp[v] == false)
            printf("ERROR: %d and %d are not found.\n", u, v);
        else if(mp[u] == false || mp[v] == false)
            printf("ERROR: %d is not found.\n", mp[u] == false ? u : v);
        else if(a == u || a == v)
            printf("%d is an ancestor of %d.\n", a, a == u ? v : u);
        else
            printf("LCA of %d and %d is %d.\n", u, v, a);
    }
    return 0;
}


/*#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
vector<int> pre, fa, depth;

void findfather(int st, int ed, int flag){
    if(st >= ed) return;
    int index = st + 1;
    while(pre[index] < pre[st]){
        index++;
        if(index > ed){
            index = ed;
            break;
        }
    }
    printf("%d %d %d\n", st, ed, index);
    depth[st + 1] = flag;
    depth[index] = flag;
    fa[st + 1] = st;
    fa[index] = st;
    findfather(st + 1, index - 1, flag + 1);
    findfather(index, ed, flag + 1);
}

void findLCA(int a, int b){
    vector<int>::iterator tempa = find(pre.begin(), pre.end(), a);
    vector<int>::iterator tempb = find(pre.begin(), pre.end(), b);
    if(tempa == pre.end() && tempb == pre.end()){
        printf("ERROR: %d and %d are not found.", a, b);
        return ;
    } else if(tempa == pre.end()){
        printf("ERROR: %d is not found.", a);
        return ;
    } else if(tempb == pre.end()){
        printf("ERROR: %d is not found.", b);
        return ;
    }
    a = tempa - pre.begin();
    b = tempb - pre.begin();
    int la, lb;
    la = a;
    lb = b;
    //cout << a << b <<endl;
    if(depth[a] > depth[b]){
        while(depth[a] != depth[b])
            a = fa[a];
        if(a == b){
            printf("%d is an ancestor of %d.", pre[b], pre[la]);
            return ;
        }
    }
    if(depth[a] < depth[b]){
        while(depth[a] != depth[b])
            b = fa[b];
        if(b == a){
            printf("%d is an ancestor of %d.", pre[a], pre[lb]);
            return ;
        }
    }
    while(a != b){
        a = fa[a];
        b = fa[b];
    }
    printf("LCA of %d and %d is %d.", pre[la], pre[lb], pre[a]);
    return ;
}

int main()
{
    int c;
    scanf("%d %d", &n, &m);
    fa.resize(m + 1);
    depth.resize(m + 1);
    for(int i = 0; i < m; i++){
        scanf("%d", &c);
        pre.push_back(c);
    }
    findfather(0, m - 1, 1);
    //cout << root <<endl;
    int a, b;
    for(int i = 0; i < n; i++){
        scanf("%d %d", &a, &b);
        findLCA(a, b);
        if(i != n - 1) printf("\n");
    }
    return 0;
}
*/
