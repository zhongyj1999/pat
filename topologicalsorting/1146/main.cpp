#include <iostream>
#include <vector>

using namespace std;
int G[1005][1005];

int main()
{
    int n, m, num, a, b;
    vector<int> ans;
    fill(G[0], G[0] + 1005 * 1005, 0);
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        G[a][b] = 1;
        G[b][a] = -1;
    }
    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        int st, ed;
        bool flag = false;
        scanf("%d", &st);
        for(int j = 0; j < n - 1; j++){
            scanf("%d", &ed);
            if(G[st][ed] == -1) flag = true;
            st = ed;
        }
        if(flag) ans.push_back(i);
    }
    for(int i = 0; i < ans.size(); i++){
        printf("%d", ans[i]);
        if(i != ans.size() - 1) printf(" ");
    }
    return 0;
}
