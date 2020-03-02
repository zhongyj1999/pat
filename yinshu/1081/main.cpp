#include <iostream>
#include <cmath>

using namespace std;
struct fraction{
    long long int up, down;
};

int gcd(long long int a, long long int b){
    return !b ? abs(a) : gcd(b, a % b);
}

fraction reduction(fraction result){
    if(result.up == 0){
        result.down = 1;
    }else{
        long long int d = gcd(abs(result.up), result.down);
        result.up /= d;
        result.down /= d;
    }
    return result;
}

fraction add(fraction f1, fraction f2){
    fraction result;
    result.up = f1.up * f2.down + f2.up * f1.down;
    result.down = f1.down * f2.down;
    return reduction(result);
}

void showResult(fraction r){
    r = reduction(r);
    if(r.down == 1) printf("%lld", r.up);
    else if(abs(r.up) > r.down){
        printf("%lld %lld/%lld", r.up / r.down, abs(r.up) % r.down, r.down);
    }else{
        printf("%lld/%lld", r.up, r.down);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    fraction ans, temp;
    ans.up = 0;
    ans.down = 1;
    for(int i = 0; i < n; i++){
        scanf("%lld/%lld", &temp.up, &temp.down);
        //printf("%lld %lld\n", temp.up, temp.down);
        reduction(temp);
        //printf("%lld %lld\n", temp.up, temp.down);
        ans = add(temp, ans);
        //printf("%lld %lld\n", ans.up, ans.down);
    }
    showResult(ans);
    return 0;
}
