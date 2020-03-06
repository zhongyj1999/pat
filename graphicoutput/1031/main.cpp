#include <iostream>

using namespace std;

int main()
{
    string s;
    int l, k, n, cnt = 0;
    cin >> s;
    l = s.length();
    k = (l + 2) / 3;
    n = l + 2 - 2 * k;
    for(int i = 1; i <= k; i++){
        if(i == k){
            for(int j = 0; j < n; j++) printf("%c", s[cnt++]);
        }else{
            printf("%c", s[cnt]);
            for(int j = 0; j < n - 2; j++) printf(" ");
            printf("%c\n", s[l - cnt - 1]);
            cnt++;
        }
    }
    return 0;
}
