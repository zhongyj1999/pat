#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    long int temp;
    vector<long int> ans;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%ld", &temp);
        ans.push_back(temp);
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%ld", &temp);
        ans.push_back(temp);
    }
    sort(ans.begin(), ans.end());
    if((n + m) % 2 == 1){
        printf("%ld", ans[(n + m) / 2]);
    }else{
        printf("%ld", ans[(n + m) / 2 - 1]);
    }
    return 0;
}
