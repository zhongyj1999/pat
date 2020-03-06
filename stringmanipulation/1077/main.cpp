#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, length = 100000000;
    scanf("%d", &n);
    getchar();
    vector<string> v, ans;
    for(int i = 0; i < n; i++){
        string s;
        getline(cin, s);
        int l = s.length();
        length = min(l, length);
        v.push_back(s);
    }
    //printf("%d\n", length);
    int cnt = 1;
    bool flag = true;
    for(int i = 0; i < length; i++){
        char temp = v[0][v[0].length() - cnt];
        for(int j = 1; j < v.size(); j++){
            if(v[j][v[j].length() - cnt] != temp){
                flag = false;
                break;
            }
        }
        cnt++;
        if(flag == false) break;
        string t;
        t = temp;
        ans.push_back(t);
    }
    if(ans.size() == 0) printf("nai");
    else{
        for(int i = ans.size() - 1; i >= 0; i--)
            cout << ans[i];
    }
    return 0;
}
