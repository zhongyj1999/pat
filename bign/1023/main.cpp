#include <iostream>
#include <string>

using namespace std;

int main()
{
    int m[25] = {0};
    int len, carry = 0, cnt = 0, have[10] = {0};
    bool flag = false;
    string s;
    cin >> s;
    len = s.length();
    for(int i = s.length() - 1; i >= 0; i--){
        int temp = stoi(s.substr(i, 1));
        have[temp]++;
        carry += temp * 2;
        m[cnt] = carry % 10;
        //printf("%d ", m[cnt]);
        have[m[cnt]]--;
        carry /= 10;
        cnt++;
    }
    if(carry > 0){
        m[cnt++] = carry;
        have[carry]--;
    }
    for(int i = 0; i < 10; i++){
        if(have[i] != 0){
            flag = true;
            break;
        }
    }
    if(flag) printf("No\n");
    else printf("Yes\n");
    for(int i = cnt - 1; i >= 0; i--){
        printf("%d", m[i]);
    }
    return 0;
}
