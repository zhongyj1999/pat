#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n, m, a;
    map<int, double> m1, m2, ans;
    double b;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %lf", &a, &b);
        m1[a] = b;
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d %lf", &a, &b);
        m2[a] = b;
    }
    for(auto it = m1.begin(); it != m1.end(); it++){
        for(auto iter = m2.begin(); iter != m2.end(); iter++){
            if(it->second * iter->second != 0.0) ans[it->first + iter->first] += it->second * iter->second;
        }
    }
    for(auto it = ans.begin(); it != ans.end(); it++){
        if(it->second == 0.0) ans.erase(it);
    }
    int cnt = ans.size();
    if(cnt == 0) printf("0");
    else printf("%d ", cnt);
    for(auto it = ans.rbegin(); it != ans.rend(); it++){
        printf("%d %.1f", it->first, it->second);
        if(cnt-- > 1) printf(" ");
    }
    return 0;
}
