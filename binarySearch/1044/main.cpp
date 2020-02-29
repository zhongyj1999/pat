//自己，没有优解直接先求出和快
#include <iostream>
#include <vector>

using namespace std;
struct node{
    int st, ed, minlose;
};
int minl = 999999999;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> dia(n + 1);
    vector<node> result;
    for(int i = 1; i <= n; i++)
        scanf("%d", &dia[i]);
    for(int i = 1; i <= n; i++){
        int total = 0;
        total += dia[i];
        if(total >= m){
            int minlose = total - m;
            if(minlose < minl){
                minl = minlose;
                result.clear();
                result.push_back(node{i, i, minl});
            } else if(minlose == minl){
                result.push_back(node{i, i, minl});
            }
            continue;
        }
        int j = 0;
        for(j = i + 1; j <= n; j++){
            total += dia[j];
            if(total >= m){
                int minlose = total - m;
                if(minlose < minl){
                    minl = minlose;
                    result.clear();
                    result.push_back(node{i, j, minl});
                } else if(minlose == minl){
                    result.push_back(node{i, j, minl});
                }
                break;
            }
        }
        if(j == n && total <= m)
            break;
    }
    for(int i = 0; i < result.size(); i++){
        printf("%d-%d\n", result[i].st, result[i].ed);
    }
    return 0;
}
