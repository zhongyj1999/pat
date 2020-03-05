/*
Most important, there are some nodes can not be linked.
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
struct node{
    int data, id, pos;
    int ahead, next;
};

bool cmp1(node a, node b){
    return a.pos < b.pos;
}

int main()
{
    int n, m, st, cnt = 1;
    scanf("%d%d%d", &st, &n, &m);
    vector<node> v(n);
    for(int i = 0; i < n; i++){
        scanf("%d%d%d", &v[i].data, &v[i].id, &v[i].next);
        if(v[i].data == st){
            st = v[i].next;
            v[i].pos = cnt++;
        }
    }
    while(st > -1){
        for(int i = 0; i < n; i++){
            if(v[i].data == st){
                st = v[i].next;
                v[i].pos = cnt++;
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(v[i].pos == 0)
            v.erase(v.begin() + i);
    }
    sort(v.begin(), v.end(), cmp1);
    for(int i = v.size() - 1; i > 0; i--){
        v[i].ahead = v[i - 1].data;
    }
    v[0].ahead = -1;
    /*
    for(int i = 0; i < v.size(); i++){
        printf("%05d %d %d %05d %05d\n", v[i].data, v[i].id, v[i].pos, v[i].ahead, v[i].next);
    }
    */
    int num = v.size() / m;
    int left = v.size() % m;
    for(int i = num - 1; i >= 0; i--){
        reverse(v.begin() + i * m, v.begin() + (i + 1) * m);
        if(left == 0 && i == num - 1) v[(i + 1) * m - 1].ahead = -1;
        else v[(i + 1) * m - 1].ahead = v[(i + 1) * m].data;
    }
    for(int i = 0; i < v.size(); i++){
        if(i >= v.size() - left && left != 0){
            if(v[i].next == -1)
                printf("%05d %d %d\n", v[i].data, v[i].id, v[i].next);
            else
                printf("%05d %d %05d\n", v[i].data, v[i].id, v[i].next);
        }
        else{
            if(v[i].ahead == -1)
                printf("%05d %d %d\n", v[i].data, v[i].id, v[i].ahead);
            else
                printf("%05d %d %05d\n", v[i].data, v[i].id, v[i].ahead);
        }
    }
    return 0;
}
