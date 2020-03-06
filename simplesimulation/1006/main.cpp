#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct node{
    char id[18];
    int st, ed;
};
int flag;
bool cmp1(node a, node b){
    if(flag == 1){
        return a.st < b.st;
    }else if(flag == 2)
        return a.ed > b.ed;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<node> v(n);
    for(int i = 0; i < n; i++){
        int h, m, s;
        scanf("%s", &v[i].id);
        scanf("%d:%d:%d", &h, &m, &s);
        v[i].st = h * 3600 + m * 60 + s;
        scanf("%d:%d:%d", &h, &m, &s);
        v[i].ed = h * 3600 + m * 60 + s;
    }
    flag = 1;
    sort(v.begin(), v.end(), cmp1);
    printf("%s ", v[0].id);
    flag = 2;
    sort(v.begin(), v.end(), cmp1);
    printf("%s", v[0].id);
    return 0;
}
