#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct node{
    double num;
    double profit, w;
};

bool cmp(node a, node b){
    return a.w > b.w;
}

int main()
{
    int n;
    double m;
    scanf("%d %lf", &n, &m);
    vector<node> kind(n);
    for(int i = 0; i < n; i++){
        scanf("%lf", &kind[i].num);
    }
    for(int i = 0; i < n; i++){
        scanf("%lf", &kind[i].profit);
        kind[i].w = kind[i].profit / kind[i].num;
    }
    sort(kind.begin(), kind.end(), cmp);
    double total = 0;
    for(int i= 0; i < n; i++){
        //printf("%d %f %f", kind[i].num, kind[i].profit, kind[i].w);
        if(m > kind[i].num){
            total += kind[i].profit;
            m -= kind[i].num;
        }else{
            total += kind[i].w * m;
            break;
        }
    }
    printf("%.2f", total);
    return 0;
}
