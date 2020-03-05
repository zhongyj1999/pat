#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
struct node{
    char data;
    int now, next;
};

int main()
{
    int sta, stb, n;
    scanf("%d %d %d", &sta, &stb, &n);
    vector<node> v, a, b;
    int now, next;
    char data;
    for(int i = 0; i < n; i++){
        scanf("%d %c %d", &now, &data, &next);
        v.push_back(node{data, now, next});
        //printf("%d %c %d\n", v[i].now, v[i].data, v[i].next);
    }
    while(sta > -1 || stb > -1){
        for(int i = 0; i < v.size(); i++){
            if(v[i].now == sta){
                a.push_back(v[i]);
                sta = v[i].next;
            }
            if(v[i].now == stb){
                b.push_back(v[i]);
                stb = v[i].next;
            }
        }
    }
    /*
    for(int i = 0; i < a.size(); i++)
        printf("%d %c %d\n", a[i].now, a[i].data, a[i].next);
    for(int i = 0; i < b.size(); i++)
        printf("%d %c %d\n", b[i].now, b[i].data, b[i].next);
    */
    int la = a.size() - 1, lb = b.size() - 1;
    int l = min(la, lb);
    if(la < 0 || lb < 0 || a[la].data != b[lb].data){
        printf("-1");
        return 0;
    }
    int temp;
    while(la >= 0 && lb >= 0){
        if(a[la].now == b[lb].now){
            temp = a[la].now;
        }else break;
        la--;
        lb--;
    }
    printf("%05d", temp);
    return 0;
}

