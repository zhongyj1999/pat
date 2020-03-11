#include <iostream>
#include <vector>

using namespace std;
int G[205][205];

int main()
{
    int n, m, a, b, num;
    fill(G[0], G[0] + 205 * 205, 0);
    scanf("%d %d", &n, &m);
    vector<vector<int>> v(n + 1);
    for(int i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
        G[a][b] = G[b][a] = 1;
    }
    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        int cnt;
        scanf("%d", &cnt);
        int flag = 0;
        vector<int> have(n + 1);
        vector<int> ans;
        for(int j = 0; j < cnt; j++){
            int temp;
            bool flag = true;
            scanf("%d", &temp);
            ans.push_back(temp);
            have[temp]++;
            for(int k = 0; k < v[temp].size(); k++){
                if(G[temp][v[temp][k]] == 1) have[v[temp][k]]++;
            }
        }
        for(int j = 1; j <= n; j++){
            //printf("%d\n", have[j]);
            if(have[j] == cnt){
                flag++;
            }
        }
        for(int j = 0; j < ans.size(); j++){
            if(have[ans[j]] != cnt) flag = false;
        }
        //printf("\n%d\n", flag);
        if(flag == cnt && flag) printf("Yes\n");
        else if(flag > cnt && flag) printf("Not Maximal\n");
        else printf("Not a Clique\n");
        //printf("\n");
    }
    return 0;
}
