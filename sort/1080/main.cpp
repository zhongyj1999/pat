#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
struct node{
    int id;
    int ge, gi;
    double tg;
    int choice[3];
};
int n, m, k;

bool cmp1(node a, node b){
    if(a.tg != b.tg)
        return a.tg > b.tg;
    else if(a.ge != b.ge)
        return a.ge > b.ge;
    else
        return a.id < b.id;
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    vector<node> stu(n);
    vector<int> sizes(m);
    vector<double> last(m);
    vector<vector<int>> school(m);
    for(int i = 0; i < m; i++){
        scanf("%d", &sizes[i]);
        //printf("%d\n", sizes[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d %d", &stu[i].ge, &stu[i].gi);
        stu[i].tg = (stu[i].ge + stu[i].gi) / 2.0;
        stu[i].id = i;
        for(int j = 0; j < k; j++){
            scanf("%d", &stu[i].choice[j]);
        }
    }
    sort(stu.begin(), stu.end(), cmp1);
    /*
    for(int i = 0; i < n; i++){
        printf("%d %d %d %f %d %d %d\n", stu[i].id, stu[i].ge, stu[i].gi, stu[i].tg, stu[i].choice[0], stu[i].choice[1], stu[i].choice[2]);
    }
    */
    for(int i = 0; i < stu.size(); i++){
        for(int j = 0; j < k; j++){
            int temp = stu[i].choice[j];
            //printf("%d %d\n", i, temp);
            if(school[temp].size() < sizes[temp]){
                school[temp].push_back(stu[i].id);
                if(school[temp].size() == sizes[temp]){
                    last[temp] = i;
                }
                //printf("%d\n", stu[i].id);
                break;
            }else if(stu[i].tg == stu[last[temp]].tg && stu[i].ge == stu[last[temp]].ge && school[temp].size() >= sizes[temp]){
                school[temp].push_back(stu[i].id);
                //printf("%d\n", stu[i].id);
                break;
            }
        }
    }
    for(int i = 0; i < m; i++){
        sort(school[i].begin(), school[i].end());
        if(school[i].size() > 0) printf("%d", school[i][0]);
        for(int j = 1; j < school[i].size(); j++){
            printf(" %d", school[i][j]);
        }
        //printf("%d ", school[i].size());
        printf("\n");
    }
    return 0;
}
