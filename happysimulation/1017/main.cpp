#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int open = 28800;
const int close = 61200;
struct node{
    int st, need;
};

bool cmp1(node a, node b){
    return a.st < b.st;
}

int main()
{
    int n, window, h, m, s, need, st;
    scanf("%d %d", &n, &window);
    vector<node> v;
    for(int i = 0; i < n; i++){
        scanf("%d:%d:%d %d", &h, &m, &s, &need);
        st = h * 3600 + m * 60 + s;
        if(st > close) continue;
        v.push_back(node{st, need * 60});
    }
    sort(v.begin(), v.end(), cmp1);
    vector<int> w(window, 28800);
    double ans = 0.0;
    for(int i = 0; i < v.size(); i++){
        int tempindex = 0, minfinish = w[0];
        for(int j = 1; j < window; j++){
            if(minfinish > w[j]){
                minfinish = w[j];
                tempindex = j;
            }
        }
        if(w[tempindex] <= v[i].st){
            w[tempindex] = v[i].st + v[i].need;
        }else{
            ans += (w[tempindex] - v[i].st);
            w[tempindex] += v[i].need;
        }
    }
    if(v.size() == 0)
        printf("0.0");
    else printf("%.1f", ans / 60.0 / v.size());
    return 0;
}
