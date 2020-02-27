#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <string>

using namespace std;
struct node{
    char id[10];
    int time, flag = 0;
};

bool cmp1(node a, node b){
    if(strcmp(a.id, b.id) != 0)
        return strcmp(a.id, b.id) < 0;
    else
        return a.time < b.time;
}

bool cmp2(node a, node b){
    return a.time < b.time;
}

int main()
{
    int n, k, maxtime = -1, tempindex = 0;
    scanf("%d %d", &n, &k);
    vector<node> record(n), car;
    for(int i = 0; i < n; i++){
        char temp[5];
        int h, m, s;
        scanf("%s %d:%d:%d %s\n", record[i].id, &h, &m, &s, temp);
        int temptime = h * 3600 + m * 60 + s;
        record[i].time = temptime;
        record[i].flag = strcmp(temp, "in") == 0 ? 1 : -1;
    }
    sort(record.begin(), record.end(), cmp1);
    map<string, int> mp;
    for(int i = 0; i < n - 1; i++){
        if(strcmp(record[i].id, record[i + 1].id) == 0 && record[i].flag == 1 && record[i + 1].flag == -1){
            car.push_back(record[i]);
            car.push_back(record[i + 1]);
            mp[record[i].id] += (record[i + 1].time - record[i].time);
            if(maxtime < mp[record[i].id])
                maxtime = mp[record[i].id];
        }
    }
    sort(car.begin(), car.end(), cmp2);
    vector<int> cnt(n);
    for(int i = 0; i < car.size(); i++){
        if(i == 0)
            cnt[i] += car[i].flag;
        else
            cnt[i] = cnt[i - 1] + car[i].flag;
    }
    for(int i = 0; i < k; i++){
        int h, m, s;
        scanf("%d:%d:%d", &h, &m, &s);
        int temptime = h * 3600 + m * 60 + s;
        int j;
        for(j = tempindex; j < car.size(); j++){
            if(car[j].time > temptime){
                printf("%d\n", cnt[j - 1]);
                break;
            } else if(j == car.size() - 1){
                printf("%d\n", cnt[j]);
            }
        }
        tempindex = j;
    }
    for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++){
        if(it->second == maxtime)
            printf("%s ", it->first.c_str());
    }
    printf("%02d:%02d:%02d", maxtime / 3600, (maxtime % 3600) / 60, maxtime % 60);
    return 0;
}
