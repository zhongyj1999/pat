#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int temp = 0, tempindex = 0, sum = -1, st = 0, ed = n - 1;
    vector<int> dp(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &dp[i]);
        temp = temp + dp[i];
        if(temp < 0){
            temp = 0;
            tempindex = i + 1;
        }else if(temp > sum){
            sum = temp;
            st = tempindex;
            ed = i;
        }
    }
    if(sum < 0) sum = 0;
    printf("%d %d %d", sum, dp[st], dp[ed]);
    return 0;
}
