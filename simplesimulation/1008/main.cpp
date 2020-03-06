#include <iostream>

using namespace std;

int main()
{
    int n, temp, st = 0, ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &temp);
        if(temp > st){
            ans += (temp - st) * 6 + 5;
            st = temp;
        }else if(temp < st){
            ans += (st - temp) * 4 + 5;
            st = temp;
        }else{
            ans += 5;
        }
    }
    printf("%d", ans);
    return 0;
}
