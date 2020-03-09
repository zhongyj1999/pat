#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int t = 0, p = 0, ans = 0;
    int l = s.length();
    for(int i = 0; i < l; i++){
        if(s[i] == 'T') t++;
    }
    for(int i = 0; i < l; i++){
        if(s[i] == 'P') p++;
        if(s[i] == 'T') t--;
        if(s[i] == 'A') ans = (ans + (p * t) % 1000000007) % 1000000007;
    }
    printf("%d", ans);
    return 0;
}
