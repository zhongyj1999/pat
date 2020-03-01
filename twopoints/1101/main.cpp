#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n), ans, sum1(n), sum2(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        if(i == 0) sum1[i] = a[i];
        else sum1[i] = sum1[i - 1] + a[i];
    }
    vector<int> b(a);
    sort(b.begin(), b.end());
    for(int i = 0; i < n; i++){
        if(i == 0) sum2[i] = b[i];
        else sum2[i] = sum2[i - 1] + b[i];
    }
    if(sum1[0] == sum2[0]) ans.push_back(a[0]);
    for(int i = 1; i < n; i++){
        if(sum1[i] == sum2[i] && sum1[i - 1] == sum2[i - 1])
            ans.push_back(b[i]);
    }
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++){
        printf("%d", ans[i]);
        if(i != ans.size() - 1) printf(" ");
    }
    printf("\n");
    return 0;
}
