#include <iostream>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        long long int a, b, c;
        bool flag = false;
        scanf("%lld %lld %lld", &a, &b, &c);
        if((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0)){
            if(a > c || b > c) flag = true;
            else{
                if((c - a) < b) flag = true;
            }
        }else if(a >= 0 && b >= 0 && c <= 0){
            if(a > c || b > c) flag = true;
        }else if(a <= 0 && b <= 0 && c >= 0){
            if(c > a || c > b) flag = true;
        }else{
            if(a + b > c) flag = true;
        }
        if(flag) printf("Case #%d: true\n", i);
        else printf("Case #%d: false\n", i);
    }
    return 0;
}
