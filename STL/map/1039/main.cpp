#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;
map<string, vector<int>> mp;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        int id, num;
        scanf("%d %d", &id, &num);
        for(int j = 0; j < num; j++){
            string s;
            cin >> s;
            mp[s].push_back(id);
        }
    }
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        cout << s << " " << mp[s].size();
        sort(mp[s].begin(), mp[s].end());
        for(int j = 0; j < mp[s].size(); j++){
            printf(" %d", mp[s][j]);
        }
        printf("\n");
    }
    return 0;
}
