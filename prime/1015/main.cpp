#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

bool isprime(int a){
    if(a == 1) return false;
    for(int i = 2; i * i <= a; i++)
        if(a % i == 0) return false;
    return true;
}

int reverseprim(int a, int c){
    vector<int> s;
    int rev = 0;
    while(a > 0){
        s.push_back(a % c);
        a /= c;
    }
    reverse(s.begin(), s.end());
    for(int i = 0; i < s.size(); i++){
        rev += s[i] * pow(c, i);
    }
    //printf("%d %d %d\n", a, c, rev);
    return rev;
}

int main()
{
    int a, c;
    while(1){
        scanf("%d", &a);
        if(a < 0) break;
        scanf("%d", &c);
        bool ip, rp;
        ip = isprime(a);
        rp = isprime(reverseprim(a, c));
        if(ip && rp) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
