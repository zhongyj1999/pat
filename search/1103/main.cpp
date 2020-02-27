#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;
int n, k, p, MaxNum = -1;
vector<int> v, ans, tempans;

/*
int intpow(int a){
    int z = a;
    for(int i = 1; i < p; i++){
        a *= z;
    }
    return a;
}
*/

void init(){
    int index = 1, temp = 0;
    while(temp <= n){
        v.push_back(temp);
        temp = pow(index, p);
        index++;
    }
}

void dfs(int index, int tempk, int tempsum, int tempMaxNum){
    if(tempk == k){
        if(tempsum == n && tempMaxNum > MaxNum){
            MaxNum = tempMaxNum;
            ans = tempans;
        }
        return;
    }
    while(index >= 1){
        if(tempsum + v[index] <= n){
            tempans[tempk] = index;
            dfs(index, tempk + 1, tempsum + v[index], tempMaxNum + index);
        }
        if(index == 1)
            return;
        index--;
    }
}

int main()
{
    scanf("%d %d %d", &n, &k, &p);
    tempans.resize(k);
    init();
    dfs(v.size() - 1, 0, 0, 0);
    if(MaxNum == -1){
        printf("Impossible");
        return 0;
    }
    printf("%d = ", n);
    for(int i = 0; i < ans.size() ; i++){
        printf("%d^%d", ans[i], p);
        if(i != ans.size() - 1)
            printf(" + ");
    }
    return 0;
}
