#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
struct node{
    char name[12], id[12];
    int grade;
};

bool cmp1(node a, node b){
    return a.grade > b.grade;
}

int main()
{
    int n, mingrade, maxgrade;
    scanf("%d", &n);
    vector<node> stu(n);
    for(int i = 0; i < n; i++){
        scanf("%s %s %d", stu[i].name, stu[i].id, &stu[i].grade);
    }
    sort(stu.begin(), stu.end(), cmp1);
    scanf("%d %d", &mingrade, &maxgrade);
    bool flag = false;
    for(int i = 0; i < stu.size(); i++){
        if(stu[i].grade >= mingrade && stu[i].grade <= maxgrade){
            flag = true;
            printf("%s %s\n", stu[i].name, stu[i].id);
        }
    }
    if(flag == false)
        printf("NONE\n");
    return 0;
}
