#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, row, line, minn = 100000, cnt = 0;
    scanf("%d", &n);
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end(), greater<int>());
    int st = 1, ed = n;
    while(st <= ed){
        if(st * ed == n){
            if(ed - st < minn){
                minn = ed - st;
                row = ed;
                line = st;
            }
            st++;
            ed--;
        }else if(st * ed < n){
            st++;
        }else if(st * ed > n){
            ed--;
        }
    }
    //printf("%d %d\n", row, line);
    vector<vector<int>> ans(row);
    for(int i = 0; i < ans.size(); i++)
        ans[i].resize(line);
    int a = 0, b = 0, sta = 0, stb = 0, eda = row - 1, edb = line - 1;
    while(cnt < n){
        ans[a][b] = v[cnt++];
        if(a == sta && b < edb){
            b++;
            if(b == edb) sta++;
        }else if(b == edb && a < eda){
            a++;
            if(a == eda) edb--;
        }else if(a == eda && b > stb){
            b--;
            if(b == stb) eda--;
        }else if(b == stb && a > sta){
            a--;
            if(a == sta) stb++;
        }
        //printf("%d %d %d %d %d %d\n", a, b, sta, eda, stb, edb);
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < line; j++){
            printf("%d", ans[i][j]);
            if(j != line - 1) printf(" ");
            else if(i != row - 1) printf("\n");
        }
    }
    return 0;
}
