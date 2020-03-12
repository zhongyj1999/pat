#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
struct node{
    string name;
    int gp, gm, gf, gt;
};
map<string, int> idx;

bool cmp(node a, node b){
    if(a.gt != b.gt)
        return a.gt > b.gt;
    else
        return a.name < b.name;
}

int main(){
    int n, m, k, score, cnt = 1;
    cin >> n >> m >> k;
    vector<node> v;
    vector<node> ans;
    string s;
    for(int i = 0; i < n; i++){
        cin >> s >> score;
        if(score >= 200){
            v.push_back(node{s, score, -1, -1, 0});
            idx[s] = cnt++;
        }
    }
    for(int i = 0; i < m; i++){
        cin >> s >> score;
        if(idx[s] != 0) v[idx[s]- 1].gm = score;
    }
    for(int i = 0; i < k; i++){
        cin >> s >> score;
        if(idx[s] != 0){
            int temp = idx[s] - 1;
            v[temp].gf = v[temp].gt = score;
            if(v[temp].gm > v[temp].gf)
                v[temp].gt = int(v[temp].gm * 0.4 + v[temp].gf * 0.6 + 0.5);
        }
    }
    for(int i = 0; i < v.size(); i++){
        if(v[i].gt >= 60) ans.push_back(v[i]);
    }
    sort(ans.begin(), ans.end(), cmp);
    for(int i = 0; i < ans.size(); i++){
        printf("%s %d %d %d %d\n", ans[i].name.c_str(), ans[i].gp, ans[i].gm, ans[i].gf, ans[i].gt);
    }
    return 0;
}
