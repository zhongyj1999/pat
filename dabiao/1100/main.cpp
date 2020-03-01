//参考，自己的写的太没得逻辑了，而且把jly写成了jiy，感觉自己绕晕了
#include <iostream>
#include <string>

using namespace std;
string a[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly",
                "aug", "sep", "oct", "nov", "dec"};
string b[13] = {"****","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo",
                "syy", "lok", "mer", "jou"};
string s;
int len;

void gets(int num){
    if(num / 13) cout << b[num / 13];
    if((num / 13) && (num % 13)) cout << " ";
    if(num % 13 || num == 0) cout << a[num % 13];
}

void getn(){
    int t1 = 0, t2 = 0;
    string s1 = s.substr(0, 3), s2;
    if(len > 4) s2 = s.substr(4, 3);
    for(int i = 1; i <= 12; i++){
        if(s1 == a[i] || s2 == a[i]) t2 = i;
        if(s1 == b[i]) t1 = i;
    }
    cout << t1 * 13 + t2;
}

int main()
{
    int n;
    cin >> n;
    getchar();
    for(int i = 0; i < n; i++){
        getline(cin, s);
        len = s.length();
        if(s[0] >= '0' && s[0] <= '9')
            gets(stoi(s));
        else
            getn();
        cout<<endl;
    }
    return 0;
}
