#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
struct bign{
    int d[100];
    int len;
    bign(){
        fill(d, d + 100, 0);
        len = 0;
    }
};

bign initial(string s){
    bign a;
    a.len = s.length();
    for(int i = 0; i < s.length(); i++){
        a.d[i] = stoi(s.substr(i, 1));
        //printf("%d %d\n", i, a.d[i]);
    }
    return a;
}

bign add(bign a, bign b){
    bign ans;
    int carry = 0;
    //printf("%d\n", a.len);
    for(int i = 0; i < a.len; i++){
        carry += a.d[i] + b.d[i];
        ans.d[i] = carry % 10;
        //printf("%d ", ans.d[i]);
        carry /= 10;
    }
    if(carry > 0){
        ans.d[a.len] = carry;
        ans.len = a.len + 1;
    }else ans.len = a.len;
    return ans;
}

bool compare(bign a, bign b){
    for(int i = 0; i < a.len; i++){
        if(a.d[i] != b.d[i]) return false;
    }
    return true;
}

int main()
{
    string a;
    int cnt;
    bign m, n, ans;
    cin >> a >> cnt;
    string b = a;
    reverse(a.begin(), a.end());
    if(a == b){
        cout << a << endl << 0;
        return 0;
    }else{
        m = initial(a);
        n = initial(b);
        int i;
        for(i = 1; i <= cnt; i++){
            ans = add(m, n);
            bign temp = ans;
            reverse(ans.d, ans.d + ans.len);
            if(compare(ans, temp)){
                for(int j = 0; j < ans.len; j++){
                    printf("%d", ans.d[j]);
                }
                printf("\n");
                printf("%d", i);
                return 0;
            }else{
                m = ans;
                n = temp;
            }
        }
    }
    for(int j = 0; j < ans.len; j++){
        printf("%d", ans.d[j]);
    }
    printf("\n");
    printf("%d", cnt);
    return 0;
}
