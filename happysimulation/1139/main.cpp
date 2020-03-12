#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
int have[10005];
vector<int> v[10005];
struct node{
    int a, b;
};

bool cmp(node a, node b){
    if(a.a != b.a)
        return a.a < b.a;
    else
        return a.b < b.b;
}

int main()
{
    int n, m, a, b, num;
    fill(have, have + 10005, 0);
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        string s, t;
        cin >> s >> t;
        if(s.length() == 5){
            a = stoi(s.substr(1));
            have[a] = -1;
        }else{
            a = stoi(s.substr(0));
            have[a] = 1;
        }
        if(t.length() == 5){
            b = stoi(t.substr(1));
            have[b] = -1;
        }else{
            b = stoi(t.substr(0));
            have[b] = 1;
        }
        v[a].push_back(b);
        v[b].push_back(a);
    }
    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        vector<node> ans;
        scanf("%d %d", &a, &b);
        a = abs(a);
        b = abs(b);
        for(int j = 0; j < v[a].size(); j++){
            if(v[a][j] == b || have[a] != have[v[a][j]]) continue;
            for(int k = 0; k < v[b].size(); k++){
                if(v[b][k] == a || v[b][k] == v[a][j] || have[b] != have[v[b][k]]) continue;
                if(find(v[v[a][j]].begin(), v[v[a][j]].end(), v[b][k]) != v[v[a][j]].end()){
                    //printf("%d %d\n", ansa[j], ansb[k]);
                    /*
                    bool flag = true;
                    for(int p = 0; p < ans.size(); p++){
                        if(ans[p].a == v[b][k] && ans[p].b == v[a][j]) flag = false;
                    }
                    */
                    ans.push_back(node{v[a][j], v[b][k]});
                }
            }
        }
        sort(ans.begin(), ans.end(), cmp);
        printf("%d\n", ans.size());
        for(int j = 0; j < ans.size(); j++)
            printf("%04d %04d\n", ans[j].a, ans[j].b);
    }
    return 0;
}
