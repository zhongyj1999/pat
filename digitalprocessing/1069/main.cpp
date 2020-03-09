#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

string sub(string s, string t){
    string ans = s;
    int carry = 0;
    for(int i = s.length() - 1; i >= 0; i--){
        if(t[i] - s[i] + carry < 0){
            ans[i] = t[i] - s[i] + '0' + 10 + carry;
            carry = -1;
        }else{
            ans[i] = t[i] - s[i] + '0' + carry;
            carry = 0;
        }
    }
    return ans;
}

int main()
{
    string s, t, ans, temp = "****";
    cin >> s;
    s.resize(4, '0');
    t = s;
    while(1){
        sort(s.begin(), s.end());
        sort(t.rbegin(), t.rend());
        if(s == t){
            cout << t << " - " << s << " = 0000" <<endl;
            return 0;
        }
        ans = sub(s, t);
        if(temp == ans) return 0;
        cout << t << " - " << s << " = " << ans<<endl;
        t = s = temp = ans;
    }
    return 0;
}
