#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n, m;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &m);
        vector<int> queen(m);
        for(int a = 0; a < m; a++){
            scanf("%d", &queen[a]);
        }
        bool flag = false;
        for(int j = 0; j < m - 1; j++){
            for(int k = j + 1; k < m; k++){
                if(queen[j] == queen[k] || abs(queen[j] - queen[k]) == k - j){
                    printf("NO\n");
                    flag = true;
                    break;
                }
            }
            if(flag == true)
                break;
        }
        if(!flag) printf("YES\n");
        flag = false;
        queen.clear();
    }
    return 0;
}
