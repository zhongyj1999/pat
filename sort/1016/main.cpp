#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;
struct node{
    string name;
    double price;
    int mm, d, h, m, time, flag;
};
int dprice = 0, hprice[25] = {0}, mprice[25] = {0};
map<string, int>mp;

bool cmp1(node a, node b){
    if(a.name == b.name)
        return a.time < b.time;
    else
        return a.name < b.name;
}

int main()
{
    int n, cnt = 1, have[1005] = {0};
    for(int i = 0; i < 24; i++){
        scanf("%d", &mprice[i]);
        hprice[i] = 60 * mprice[i];
        dprice += hprice[i];
    }
    scanf("%d", &n);
    vector<node> call(n), truecall;
    for(int i = 0; i < n; i++){
        string temp;
        cin >> call[i].name;
        scanf("%d:%d:%d:%d", &call[i].mm, &call[i].d, &call[i].h, &call[i].m);
        cin >> temp;
        call[i].flag = (temp == "on-line") ? 1 : -1;
        call[i].time = call[i].d * 24 * 60 + call[i].h * 60 + call[i].m;
        call[i].price += call[i].d * dprice;
        for(int j = 0; j < call[i].h; j++){
            call[i].price += hprice[j];
        }
        if(call[i].m > 0)
            call[i].price += mprice[call[i].h] * call[i].m;
    }
    sort(call.begin(), call.end(), cmp1);
    for(int i = 0; i < n - 1; i++){
        if(call[i].name == call[i + 1].name && call[i].flag == 1 && call[i + 1].flag == -1){
            truecall.push_back(call[i]);
            truecall.push_back(call[i + 1]);
            if(mp[call[i].name] == 0){
                mp[call[i].name] = cnt++;
            }
            have[mp[call[i].name]] += 2;
        }
    }
    int k = 0;
    for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++){
        //printf("%s %d %d\n", it->first.c_str(), it->second, have[it->second]);
        double total = 0;
        int i = have[it->second];
        cout << truecall[k].name;
        printf(" %02d\n", truecall[0].mm);
        for(int j = 0; j < i; j += 2){
            double temp = (truecall[k + 1].price - truecall[k].price) / 100.0;
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", truecall[k].d, truecall[k].h, truecall[k].m, truecall[k + 1].d, truecall[k + 1].h, truecall[k + 1].m, (truecall[k + 1].time - truecall[k].time), temp);
            total += temp;
            k += 2;
        }
        printf("Total amount: $%.2f\n", total);
    }
    return 0;
}
