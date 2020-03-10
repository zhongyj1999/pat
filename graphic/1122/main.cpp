#include <iostream>
#include <vector>

using namespace std;
int G[205][205];

int main()
{
    int n, m, num;
    fill(G[0], G[0] + 205 * 205, 0);
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        G[a][b] = G[b][a] = 1;
    }
    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        int cnt, st, ed, temp;
        vector<int> have(n + 1);
        bool flag = true;
        scanf("%d %d", &cnt, &st);
        temp = st;
        for(int j = 0; j < cnt - 1; j++){
            scanf("%d", &ed);
            if(G[temp][ed] != 1) flag = false;
            if(have[ed] == 0) have[ed] = 1;
            else if(j <= cnt - 2 && have[ed] != 0) flag = false;
            //printf("%d %d %d\n", temp, ed, flag);
            temp = ed;
        }
        for(int k = 1; k <= n; k++){
            if(have[k] != 1){
                flag = false;
                break;
            }
        }
        //cout << temp << ' ' << ed <<endl;
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
