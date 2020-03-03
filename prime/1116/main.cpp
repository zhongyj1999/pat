#include <iostream>

using namespace std;

bool isprim(int a){
    if(a == 1) return false;
    for(int i = 2; i * i <= a; i++)
        if(a % i == 0) return false;
    return true;
}

int main()
{
    int n, m, temp, have[10000] = {0};
    bool exist[10000] = {false};
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &temp);
        have[temp] = i;
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d", &temp);
        if(have[temp] == 0){
            printf("%04d: Are you kidding?\n", temp);
        }else{
            if(!exist[temp]){
                if(have[temp] == 1)
                    printf("%04d: Mystery Award\n", temp);
                else if(isprim(have[temp])){
                    printf("%04d: Minion\n", temp);
                }else
                    printf("%04d: Chocolate\n", temp);
                exist[temp] = true;
            }else{
                printf("%04d: Checked\n", temp);
            }
        }
    }
    return 0;
}
