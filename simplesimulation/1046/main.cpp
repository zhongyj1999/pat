#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, st, ed;
    scanf("%d", &n);
    vector<int> dis(n + 1), total(n + 1);
    for(int i = 1; i <= n; i++){
        scanf("%d", &dis[i]);
        total[i] = dis[i] + total[i - 1];
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d", &st, &ed);
        int l = abs(total[st - 1] - total[ed - 1]);
        printf("%d\n", l <= (total[n] - l) ? l : total[n] - l);
    }
    return 0;
}



/*
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m, st, ed, total = 0;
    scanf("%d", &n);
    vector<int> dis(n + 1);
    vector<vector<int>> l(n + 1);
    for(int i = 0; i < l.size(); i++)
        l[i].resize(n + 1);
    for(int i = 1; i <= n; i++){
        scanf("%d", &dis[i]);
        total += dis[i];
    }
    for(int i = 1; i < n; i++){
        for(int j = i + 1; j <= n; j++){
            int l1 = 0;
            for(int k = i; k < j; k++){
                l1 += dis[k];
            }
            l[i][j] = l[j][i] = l1 <= (total - l1) ? l1 : total - l1;
        }
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d", &st, &ed);
        printf("%d\n", l[st][ed]);
    }
    return 0;
}
*/
