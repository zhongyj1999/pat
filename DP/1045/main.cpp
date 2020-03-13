#include <iostream>

using namespace std;
int color[201], a[10001], dp[10001];

int main()
{
    int n, m, k, temp, num = 0, maxn = -1;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++){
        scanf("%d", &temp);
        color[temp] = i;
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        scanf("%d", &temp);
        if(color[temp] >= 1){
            a[num++] = color[temp];
        }
    }
    for(int i = 0; i < num; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(a[i] >= a[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        maxn = max(dp[i], maxn);
    }
    printf("%d", maxn);
    return 0;
}


