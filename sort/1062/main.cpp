#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
struct node{
    int id, v, t, flag, total;
};
int n, L, H;
vector<node> people;

bool cmp1(node a, node b){
    if(a.flag == b.flag){
        if(a.total == b.total){
            if(a.v == b.v){
                return a.id < b.id;
            }else{
                return a.v > b.v;
            }
        }else{
            return a.total > b.total;
        }
    }else{
        return a.flag < b.flag;
    }
}

int main()
{
    int cnt = 0;
    scanf("%d %d %d", &n, &L, &H);
    for(int i = 0 ; i < n; i++){
        int id, v, t, flag = 0, total;
        scanf("%d %d %d", &id, &v, &t);
        total = v + t;
        if(v >= H && t >= H){
            flag = 1;
            cnt++;
        }else if(v >= H && t >= L && t < H){
            flag = 2;
            cnt++;
        }else if(v >= L && v < H && t < H && t >= L && v >= t){
            flag = 3;
            cnt++;
        }else if(v < L || t < L){
            flag = 5;
        }else{
            flag = 4;
            cnt++;
        }
        if(flag != 5)
            people.push_back(node{id, v, t, flag, total});
    }
    sort(people.begin(), people.end(), cmp1);
    printf("%d\n", cnt);
    for(int i = 0; i < people.size(); i++){
        printf("%d %d %d\n", people[i].id, people[i].v, people[i].t);
    }
    return 0;
}
