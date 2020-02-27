#include <iostream>
using namespace std;

int main()
{
    int n, have[10005] = {0}, v[100005];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
        have[v[i]]++;
    }
    for(int i = 0; i < n; i++){
        if(have[v[i]] == 1){
            printf("%d", v[i]);
            return 0;
        }
    }
    printf("None");
    return 0;
}
