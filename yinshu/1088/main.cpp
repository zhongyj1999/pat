#include <iostream>
#include <algorithm>

using namespace std;
struct fraction{
    long long int up, down;
};

int gcd(long long int a, long long int b){
    return !b ? abs(a) : gcd(b, a % b);
}

fraction reduction(fraction result){
    if(result.down < 0){
        result.up = -result.up;
        result.down = - result.down;
    }
    if(result.up == 0){
        result.down = 1;
    }else{
        int d = gcd(abs(result.up), result.down);
        result.up /= d;
        result.down /= d;
    }
    return result;
}

void showResult(fraction r){
    if(r.down == 0){
        printf("Inf");
        return ;
    }
    if(r.up < 0)
        printf("(");
    if(r.down == 1){
        printf("%lld", r.up);
    }else if(abs(r.up) > r.down){
        printf("%lld %lld/%lld", r.up / r.down, abs(r.up) % r.down, r.down);
    }else{
        printf("%lld/%lld", r.up, r.down);
    }
    if(r.up < 0)
        printf(")");
}

fraction add(fraction a, fraction b){
    fraction ans;
    ans.up = a.up * b.down + a.down * b.up;
    ans.down = a.down * b.down;
    return reduction(ans);
}

fraction sub(fraction a, fraction b){
    fraction ans;
    ans.up = a.up * b.down - a.down * b.up;
    ans.down = a.down * b.down;
    return reduction(ans);
}

fraction multi(fraction a, fraction b){
    fraction ans;
    ans.up = a.up * b.up;
    ans.down = a.down * b.down;
    return reduction(ans);
}

fraction divi(fraction a, fraction b){
    fraction ans;
    ans.up = a.up * b.down;
    ans.down = a.down * b.up;
    return reduction(ans);
}

int main()
{
    fraction a, b, ans;
    scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
    a = reduction(a);
    b = reduction(b);
    //printf("%lld %lld\n", b.up, b.down);
    for(int i = 0; i < 4; i++){
        showResult(a);
        if(i == 0) printf(" + ");
        else if(i == 1) printf(" - ");
        else if(i == 2) printf(" * ");
        else printf(" / ");
        showResult(b);
        printf(" = ");
        if(i == 0) ans = add(a, b);
        else if(i == 1) ans = sub(a, b);
        else if(i == 2) ans = multi(a, b);
        else ans = divi(a, b);
        showResult(ans);
        printf("\n");
    }
    return 0;
}
