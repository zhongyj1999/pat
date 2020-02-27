#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
struct node{
    int rank;
    string school;
    double tws;
    int ns;
};
map<string, int>mp;

bool cmp1(node a, node b){
    if(a.tws != b.tws)
        return a.tws > b.tws;
    else if(a.ns != b.ns)
        return a.ns < b.ns;
    else
        return a.school < b.school;
}

string lower(string s){
    for(int i = 0; i < s.size(); i++)
        s[i] = tolower(s[i]);
    return s;
}

int main()
{
    int n, cnt = 1, count = 1;
    vector<node> stu;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        string id, school;
        double score;
        cin >> id >> score >> school;
        if(id.substr(0, 1) == "B")
            score /= 1.5;
        else if(id.substr(0, 1) == "T")
            score *= 1.5;
        school = lower(school);
        if(mp[school] == 0){
            mp[school] = cnt++;
            stu.push_back(node{0, school, score, 1});
        }else{
            stu[mp[school] - 1].tws += score;
            stu[mp[school] - 1].ns++;
        }
    }
    for(int i = 0; i < stu.size(); i++){
        stu[i].tws = int(stu[i].tws);
    }
    sort(stu.begin(), stu.end(), cmp1);
    printf("%d\n", cnt - 1);
    stu[0].rank = count++;
    for(int i = 0; i < stu.size(); i++){
        if(i > 0){
            if(stu[i].tws == stu[i - 1].tws){
                stu[i].rank = stu[i - 1].rank;
                count++;
            }else{
                stu[i].rank = count++;
            }
        }
        printf("%d ", stu[i].rank);
        cout << stu[i].school;
        printf(" %d %d\n", int(stu[i].tws), stu[i].ns);
    }
    return 0;
}
