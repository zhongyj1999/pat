#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int w[10005], choice[10005][105], dp[105];

int main()
{
    int n, num;
    vector<int> ans;
    scanf("%d %d", &n, &num);
    for(int i = 1; i <= n; i++){
        scanf("%d", &w[i]);
    }
    sort(w + 1, w + n + 1, greater<int>());
    for(int i = 1; i <= n; i++){
        for(int j = num; j >= w[i]; j--){
            int temp = dp[j - w[i]] + w[i];
            if(dp[j] <= temp){
                dp[j] = temp;
                choice[i][j] = 1;
            }
        }
    }
    if(dp[num] != num) printf("No Solution");
    else{
        int index = num, v = n;
        while(index > 0){
            if(choice[v][index] == 1){
                ans.push_back(w[v]);
                index -= w[v];
            }
            v--;
        }
    }
    for(int i = 0; i < ans.size(); i++){
        if(i != 0) printf(" ");
        printf("%d", ans[i]);
    }
    return 0;
}
