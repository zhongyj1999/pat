#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
struct node{
    int id, total = 0, perfect, rank;
    vector<int> score;
    bool isshow = false;
};
int n, m, k;

bool cmp1(node a, node b){
    if(a.total != b.total)
        return a.total > b.total;
    else if(a.perfect != b.perfect)
        return a.perfect > b.perfect;
    else
        return a.id < b.id;
}

int main()
{
    scanf("%d%d%d", &n, &k, &m);
    vector<node> stu(n + 1);
    vector<int> perf(k + 1);
    for(int i = 1; i <= n; i++)
        stu[i].score.resize(k + 1, -1);
    for(int i = 1; i <= k; i++){
        scanf("%d", &perf[i]);
    }
    for(int i = 0; i < m; i++){
        int num, sn, sco;
        scanf("%d %d %d", &num, &sn, &sco);
        stu[num].id = num;
        stu[num].score[sn] = max(stu[num].score[sn], sco);
        if(sco != -1)
            stu[num].isshow = true;
        else if(stu[num].score[sn] == -1)
            stu[num].score[sn] = -2;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if(stu[i].score[j] != -1 && stu[i].score[j] != -2)
                stu[i].total += stu[i].score[j];
            if(stu[i].score[j] == perf[j])
                stu[i].perfect++;
        }
    }
    sort(stu.begin() + 1, stu.end(), cmp1);
    for(int i = 1; i <= n; i++){
        stu[i].rank = i;
        if(i != 1 && stu[i].total == stu[i - 1].total)
            stu[i].rank = stu[i - 1].rank;
    }
    for(int i = 1; i <= n; i++){
        if(stu[i].isshow == true){
            printf("%d %05d %d", stu[i].rank, stu[i].id, stu[i].total);
            for(int j = 1; j <= k; j++){
                if(stu[i].score[j] != -1 && stu[i].score[j] != -2)
                    printf(" %d", stu[i].score[j]);
                else if(stu[i].score[j] == -1)
                    printf(" -");
                else
                    printf(" 0");
            }
            printf("\n");
        }
    }
    return 0;
}
