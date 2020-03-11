#include <iostream>
#include <vector>

using namespace std;
int G[205][205];

int main()
{
    int n, m, a, b, num, dis, mindis = 1000000000, minpos;
    fill(G[0], G[0] + 205 * 205, 0);
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &dis);
        G[a][b] = G[b][a] = dis;
    }
    scanf("%d", &num);
    for(int i = 1; i <= num; i++){
        int cnt, st, ed, flag1 = 1, flag2 = 0, total = 0;
        vector<int> have(n + 1);
        scanf("%d %d", &cnt, &st);
        for(int j = 0; j < cnt - 1; j++){
            scanf("%d", &ed);
            if(G[st][ed] == 0) flag1 = -1;
            else{
                total += G[st][ed];
                have[ed]++;
            }
            st = ed;
        }
        for(int j = 1; j <= n; j++){
            if(have[j] == 0) flag2 = -1;
            else{
                if(flag2 == 0 || flag2 == 1){
                    if(have[j] == 1) flag2 = 1;
                    else if(have[j] > 1) flag2 = 2;
                }
            }
        }
        printf("Path %d: ", i);
        if(flag1 == 1 && flag2 > 0){
            if(flag2 == 1) printf("%d (TS simple cycle)\n", total);
            else printf("%d (TS cycle)\n", total);
            if(total < mindis){
                mindis = total;
                minpos = i;
            }
        }else if(flag1 == 1 && flag2 == -1){
            printf("%d (Not a TS cycle)\n", total);
        }else
            printf("NA (Not a TS cycle)\n");
    }
    printf("Shortest Dist(%d) = %d", minpos, mindis);
    return 0;
}
