#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;
int have[100005];
int is[100005] = {0};

int main()
{
    int n, m, a, b, c, cnt = 0;
    fill(have, have + 100005, -2);
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &a, &b);
        have[a] = b;
        have[b] = a;
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d", &c);
        if(have[c] == -2){
            have[c] = -1;
        }else{
            is[have[c]] = 1;
            //printf("%d %d\n", have[c], is[have[c]]);
        }
        v.push_back(c);
    }
    sort(v.begin(), v.end());
    //printf("%d\n", v.size());
    for(int i = 0; i < v.size(); i++){
        if(have[v[i]] != -1){
            if(is[v[i]] == 1){
                have[v[i]] = -2;
            }else{
                cnt++;
                have[v[i]] = -1;
                //printf("%d\n", v[i]);
            }
        }else
            cnt++;
    }
    printf("%d\n", cnt);
    for(int i = 0; i < v.size(); i++){
        if(have[v[i]] == -1){
            printf("%05d", v[i]);
            if(cnt-- > 1)
                printf(" ");
        }
    }
    return 0;
}
