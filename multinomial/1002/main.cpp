#include <iostream>
#include <map>

using namespace std;
map<int, double> mp;

int main()
{
    int n, m, a;
    double b;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %lf", &a, &b);
        mp[a] += b;
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d %lf", &a, &b);
        mp[a] += b;
    }
    for(auto it = mp.begin(); it != mp.end(); it++){
        if(it->second == 0.0) mp.erase(it);
    }
    int cnt = mp.size();
    if(cnt == 0) printf("0");
    else printf("%d ", cnt);
    for(auto it = mp.rbegin(); it != mp.rend(); it++){
        printf("%d %.1f", it->first, it->second);
        if(cnt-- > 1) printf(" ");
    }
    return 0;
}
