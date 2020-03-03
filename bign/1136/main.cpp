#include <iostream>
#include <algorithm>

using namespace std;
string s;

void add(string t){
    int len = s.length(), carry = 0;
    for(int i = 0; i < len; i++){
        s[i] = s[i] + t[i] + carry - '0';
        carry = 0;
        if(s[i] > '9'){
            s[i] = s[i] - 10;
            carry = 1;
        }
    }
    if(carry) s += '1';
    reverse(s.begin(), s.end());
}

int main()
{
    int i;
    cin >> s;
    for(i = 1; i <= 10; i++){
        string t = s;
        reverse(s.begin(), s.end());
        if(s == t){
            cout << s << " is a palindromic number.";
            return 0;
        }
        cout << t << " + " << s << " = ";
        add(t);
        cout << s << endl;
    }
    cout << "Not found in 10 iterations.";
    return 0;
}
