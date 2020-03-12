#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int n, m, num, a, b;
    scanf("%d %d", &n, &m);
    vector<vector<int>> v(n);
    for(int i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        vector<int> color(n);
        set<int> s;
        bool flag = true;
        for(int j = 0; j < n; j++){
            scanf("%d", &color[j]);
            s.insert(color[j]);
        }
        for(int j = 0; j < n; j++){
            for(int k = 0; k < v[j].size(); k++){
                if(color[j] == color[v[j][k]]){
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }
        if(flag) printf("%d-coloring\n", s.size());
        else printf("No\n");
    }
    return 0;
}
