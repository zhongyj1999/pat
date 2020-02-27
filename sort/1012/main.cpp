#include <cstdio>
#include <algorithm>

using namespace std;
struct node{
    int id, best;
    int score[4], rk[4];
}stu[2005];
int exist[1000000], flag = -1;

bool cmp1(node a, node b){
    return a.score[flag] > b.score[flag];
}

int main()
{
    int n, m, id;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d %d %d %d", &stu[i].id, &stu[i].score[1], &stu[i].score[2], &stu[i].score[3]);
        stu[i].score[0] = (stu[i].score[1] + stu[i].score[2] + stu[i].score[3]) / 3.0 + 0.5;
        //printf("%d\n", stu[i].score[0]);
    }
    for(flag = 0; flag <= 3; flag++){
        sort(stu, stu + n, cmp1);
        stu[0].rk[flag] = 1;
        for(int i = 1; i < n; i++){
            stu[i].rk[flag] = i + 1;
            if(stu[i].score[flag] == stu[i - 1].score[flag])
                stu[i].rk[flag] = stu[i - 1].rk[flag];
        }
    }
    for(int i = 0; i < n; i++){
        exist[stu[i].id] = i + 1;
        stu[i].best = 0;
        int minn = stu[i].rk[0];
        for(int j = 1; j <= 3; j++){
            if(stu[i].rk[j] < minn){
                minn = stu[i].rk[j];
                stu[i].best = j;
            }
        }
    }
    char c[5] = {'A', 'C', 'M', 'E'};
    for(int i = 0; i < m; i++){
        scanf("%d", &id);
        int temp = exist[id];
        if(temp){
            int best = stu[temp - 1].best;
            printf("%d %c\n", stu[temp - 1].rk[best], c[best]);
        } else{
            printf("N/A\n");
        }
    }
    return 0;
}
