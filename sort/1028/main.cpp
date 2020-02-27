#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
struct node{
    int id, score;
    char name[10];
}stu[100005];

bool cmp1(node a, node b){
    return a.id < b.id;
}

bool cmp2(node a, node b){
    if(strcmp(a.name, b.name) == 0){
        return a.id < b.id;
    } else{
        return strcmp(a.name, b.name) < 0;
    }
}

bool cmp3(node a, node b){
    if(a.score ==  b.score){
        return a.id < b.id;
    } else{
        return a.score < b.score;
    }
}

int main()
{
    int n, mode;
    scanf("%d %d", &n, &mode);
    for(int i = 0; i < n; i++){
        scanf("%d %s %d", &stu[i].id, &stu[i].name, &stu[i].score);
        //cout << stu[i].id << stu[i].name << stu[i].score <<endl;
    }
    if(mode == 1){
        sort(stu, stu + n, cmp1);

    } else if(mode == 2){
        sort(stu, stu + n, cmp2);
    } else{
        sort(stu, stu + n, cmp3);
    }
    for(int i = 0; i < n; i++){
        printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].score);
        //printf("%6d %s %d\n", stu[i].id, stu[i].name, stu[i].score);
    }
    return 0;
}
