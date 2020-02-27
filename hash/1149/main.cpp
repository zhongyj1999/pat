#include <iostream>
#include <vector>

using namespace std;
vector<int> v[100005];
bool is[100005];

int main()
{
    int n, m, num;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 0; i < m; i++){
        bool flag = false;
        fill(is, is + 100005, false);
        vector<int> s;
        scanf("%d", &num);
        int temp;
        for(int j = 0; j < num; j++){
            scanf("%d", &temp);
            s.push_back(temp);
            for(int k = 0; k < v[temp].size(); k++){
                is[v[temp][k]] = true;
            }
        }
        for(int l = 0; l < s.size(); l++){
            if(is[s[l]] == true){
                flag = true;
                break;
            }
        }
        if(flag == true)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
