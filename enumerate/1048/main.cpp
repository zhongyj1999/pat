#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> v(n);
    for(int i = 0; i < n; i++) scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    int st = 0;
    int ed = n - 1;
    while(st < ed){
        //printf("%d %d\n", v[st], v[ed]);
        if(v[st] + v[ed] < m) st++;
        else if(v[st] + v[ed] > m) ed--;
        else{
            printf("%d %d", v[st], v[ed]);
            return 0;
        }
    }
    printf("No Solution");
    return 0;
}
