#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int inf = 99999999;
struct station{
    double price, dis;
};

bool cmp(station a, station b){
    return a.dis < b.dis;
}

int main()
{
    double cmax, d, davg;
    int n;
    scanf("%lf %lf %lf %d", &cmax, &d, &davg, &n);
    vector<station> sta(n + 1);
    sta[0] = {0.0, d};
    for(int i = 1; i <= n; i++){
        scanf("%lf%lf", &sta[i].price, &sta[i].dis);
    }
    sort(sta.begin(), sta.end(), cmp);
    double nowdis = 0.0, maxdis = 0.0, nowprice = 0.0, totalprice = 0.0, leftdis = 0.0;
    if(sta[0].dis != 0){
        printf("The maximum travel distance = 0.00");
        return 0;
    } else {
        nowprice = sta[0].price;
    }
    while(nowdis < d){
        maxdis = nowdis + cmax * davg;
        double minPrinceDis = 0, minprice = inf;
        int flag = 0;
        for(int i = 1; i <= n && sta[i].dis <= maxdis; i++){
            if(sta[i].dis <= nowdis) continue;
            if(sta[i].price < nowprice){
                totalprice += (sta[i].dis - nowdis - leftdis) * nowprice / davg;
                leftdis = 0.0;
                nowprice = sta[i].price;
                nowdis = sta[i].dis;
                flag = 1;
                break;
            }
            if(sta[i].price < minprice){
                minprice = sta[i].price;
                minPrinceDis = sta[i].dis;
            }
        }
        if(flag == 0 && minprice != inf){
            totalprice += (nowprice * (cmax - leftdis / davg));
            leftdis = cmax * davg - (minPrinceDis - nowdis);
            nowprice = minprice;
            nowdis = minPrinceDis;
        }
        if(flag == 0 && minprice == inf){
            nowdis += cmax * davg;
            printf("The maximum travel distance = %.2f", nowdis);
            return 0;
        }
    }
    printf("%.2f", totalprice);
    return 0;
}
