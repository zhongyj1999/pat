#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
map<int, vector<string>> mp;

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    for(int i = 0; i < m; i++){
        string s;
        int cnt;
        cin >> s >> cnt;
        for(int j = 0; j < cnt; j++){
            int temp;
            scanf("%d", &temp);
            mp[temp].push_back(s);
        }
    }
    for(int i = 1; i <= n; i++){
        printf("%d %d\n", i, mp[i].size());
        sort(mp[i].begin(), mp[i].end());
        for(int j = 0; j < mp[i].size(); j++)
            printf("%s\n", mp[i][j].c_str());
    }
    return 0;
}
