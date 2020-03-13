#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, num;
    scanf("%d %d", &n, &num);
    vector<int> v(n), w(n), dp(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
        w[n - i - 1] = i + 1;
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        dp[i] = 0;
    }
    return 0;
}
