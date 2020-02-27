#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
struct node {
    string t;
    int value;
};

bool cmp(const node &a, const node &b){
    return a.value != b.value ? a.value > b.value : a.t < b.t;
}

int main(){
    int n, k, num;
    string s;
    cin >> n >> k;
    vector<node> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i].t >> v[i].value;
    for(int i = 1; i <= k; i++){
        cin >> num >> s;
        printf("Case %d: %d %s\n", i, num, s.c_str());
        vector<node> ans;
        int cnt = 0, sum = 0;
        if(num == 1){
            for(int j = 0; j < n; j++)
                if(v[j].t[0] == s[0]) ans.push_back(v[j]);
        }else if(num == 2){
            for(int j = 0; j < n; j++){
                if(v[j].t.substr(1, 3) == s){
                    cnt++;
                    sum += v[j].value;
                }
            }
            if(cnt != 0) printf("%d %d\n", cnt, sum);
        }else if(num == 3){
            unordered_map<string, int> m;
            for(int j = 0; j < n; j++)
                if(v[j].t.substr(4, 6) == s) m[v[j].t.substr(1, 3)]++;
            for(auto it : m) ans.push_back({it.first, it.second});
        }
        sort(ans.begin(), ans.end(), cmp);
        for(int j = 0; j < ans.size(); j++)
            printf("%s %d\n", ans[j].t.c_str(), ans[j].value);
        if(((num == 1 || num ==3) && ans.size() == 0) || (num == 2 && cnt == 0))
            printf("NA\n");
    }
    return 0;
}

/*
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
struct node{
    int level, site, data, number, score;
};
int have[1005];
bool cmp1(node a, node b){
    if(a.score != b.score)
        return a.score > b.score;
    else if(a.site != b.site)
        return a.site < b.site;
    else if(a.data != b.data)
        return a.data < b.data;
    return a.number < b.number;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<node> stu(n);
    vector<int> t(m), c(m);
    vector<vector<node>> tempstu(m);
    for(int i = 0; i < n; i++){
        int score;
        string temp;
        cin >> temp >> score;
        stu[i].level = temp[0] - 'A';
        stu[i].site = stoi(temp.substr(1, 3));
        stu[i].data = stoi(temp.substr(4, 6));
        stu[i].number = stoi(temp.substr(10, 3));
        stu[i].score = score;
        //printf("%d %d %d %d %d\n", stu[i].level, stu[i].site, stu[i].data, stu[i].number, stu[i].score);
    }
    for(int i = 0; i < m; i++){
        int type;
        string temp;
        cin >> type >> temp;
        t[i] = type;
        if(temp.size() == 1)
            c[i] = temp[0] - 'A';
        else
            c[i] = stoi(temp);
        //printf("%d %d\n", t[i], c[i]);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(t[j] == 1){
                if(stu[i].level == c[j]){
                    tempstu[j].push_back(stu[i]);
                }
            }else if(t[j] == 2){
                if(stu[i].site == c[j]){
                    tempstu[j].push_back(stu[i]);
                }
            }else{
                if(stu[i].data == c[j]){
                    tempstu[j].push_back(stu[i]);
                }
            }
        }
    }
    vector<int> mp(m);
    for(int i = 0; i < m; i++){
        int total = 0, cnt = 0;
        printf("Case %d: %d ", i + 1, t[i]);
        if(t[i] == 1){
            if(c[i] == 0) printf("A\n");
            else if(c[i] == 1) printf("B\n");
            else printf("T\n");
        }
        else
            printf("%d\n", c[i]);
        if(tempstu[i].size() != 0){
            if(t[i] == 1){
                sort(tempstu[i].begin(), tempstu[i].end(), cmp1);
                for(int j = 0; j < tempstu[i].size(); j++){
                    if(c[i] == 0) printf("A");
                    else if(c[i] == 1) printf("B");
                    else printf("T");
                    printf("%d%d%d %d\n", tempstu[i][j].site, tempstu[i][j].data, tempstu[i][j].number, tempstu[i][j].score);
                }
            }else if(t[i] == 3){
                for(int j = 0; j < tempstu[i].size(); j++){
                    if(have[tempstu[i][j].site] == 0){
                        have[tempstu[i][j].site] = 1;
                        mp[cnt++] = tempstu[i][j].site;
                    }else
                        have[tempstu[i][j].site]++;
                }
                for(int q = 0; q < cnt; q++){
                    for(int w = q + 1; w < cnt; w++){
                        if(have[mp[w]] > have[mp[q]] || (have[mp[w]] == have[mp[q]] && mp[w] < mp[q])){
                            int e;
                            e = mp[q];
                            mp[q] = mp[w];
                            mp[w] = e;
                        }
                    }
                }
                for(int temp = 0; temp < cnt; temp++){
                    printf("%d %d\n", mp[temp], have[mp[temp]]);
                }
            }else{
                for(int j = 0; j < tempstu[i].size(); j++){
                    total += tempstu[i][j].score;
                }
                printf("%d %d\n", tempstu[i].size(), total);
            }
        }else
            printf("NA\n");
    }
    mp.clear();
    for(int i = 0; i < m; i++){
        for(int j = 0; j < tempstu[i].size(); j++){
            printf("%d %d %d %d %d %d %d\n", i, t[i], tempstu[i][j].level, tempstu[i][j].site, tempstu[i][j].data, tempstu[i][j].number, tempstu[i][j].score);
        }
    }
    return 0;
}
*/
