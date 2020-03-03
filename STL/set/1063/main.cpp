#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n, m, num, temp;
    scanf("%d", &n);
    set<int> s[55];
    for(int i = 1; i <= n; i++){
        scanf("%d", &num);
        for(int j = 0; j < num; j++){
            scanf("%d", &temp);
            s[i].insert(temp);
        }
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        int a, b, total, ans = 0;
        double rate;
        scanf("%d %d", &a, &b);
        total = s[a].size() + s[b].size();
        //printf("%d %d\n", total, ans);
        for(auto j = s[a].begin(); j != s[a].end(); j++){
            auto k = s[b].find(*j);
            if(k != s[b].end()){
                ans++;
                total--;
            }
        }
        //printf("%d %d\n", total, ans);
        rate = ans * 1.0 * 100/ total;
        printf("%.1f%%\n", rate);
    }
    return 0;
}
