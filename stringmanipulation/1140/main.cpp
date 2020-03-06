#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num, n, cnt = 1;
    scanf("%d %d", &num, &n);
    vector<vector<int>> v(n);
    v[0].push_back(num);
    for(int i = 1; i < n; i++){
        for(int j = 0; j < v[i - 1].size(); j++){
            if(j == v[i - 1].size() - 1){
                v[i].push_back(v[i - 1][j]);
                v[i].push_back(cnt);
                cnt = 1;
            }else{
                if(v[i - 1][j] == v[i - 1][j + 1]){
                    cnt++;
                }else{
                    v[i].push_back(v[i - 1][j]);
                    v[i].push_back(cnt);
                    cnt = 1;
                }
            }
        }
    }
    int temp = n - 1;
    for(int i = 0; i < v[temp].size(); i++)
        printf("%d", v[temp][i]);
    return 0;
}
