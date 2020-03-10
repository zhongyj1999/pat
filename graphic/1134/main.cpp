#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m, num, cnt, node;
    scanf("%d %d", &n, &m);
    vector<vector<int>> v(n);
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].push_back(i);
        v[b].push_back(i);
    }
    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        vector<int> flag(m, 0);
        scanf("%d", &cnt);
        for(int j = 0; j < cnt; j++){
            scanf("%d", &node);
            for(int k = 0; k < v[node].size(); k++){
                flag[v[node][k]] = 1;
            }
        }
        bool exsit = true;
        for(int j = 0; j < m; j++){
            if(flag[j] == 0){
                exsit = false;
                break;
            }
        }
        if(exsit) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
