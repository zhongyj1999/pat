#include <iostream>

using namespace std;

int main()
{
    long int n, m;
    bool flag = false;
    scanf("%ld", &n);
    m = n;
    printf("%ld=", n);
    for(long int i = 2; i * i <= m; i++){
        int cnt = 0;
        while(n % i == 0){
            flag = true;
            n /= i;
            cnt++;
        }
        if(cnt > 1){
            printf("%ld^%d", i, cnt);
            if(n != 1) printf("*");
        }else if(cnt == 1){
            printf("%ld", i);
            if(n != 1) printf("*");
        }
    }
    if(!flag) printf("%ld", m);
    return 0;
}
