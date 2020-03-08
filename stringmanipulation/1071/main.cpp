#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main()
{
    string s;
    int maxn = -1;
    map<string, int> mp;
    set<string> ans;
    getline(cin, s);
    int cnt = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = tolower(s[i]);
        }
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            cnt++;
            if(i == s.length() - 1){
                string t = s.substr(s.length() - cnt);
                //cout << t<<endl;
                mp[t]++;
                cnt = 0;
                maxn = max(maxn, mp[t]);
            }
        }else{
            if(cnt > 0){
                string t = s.substr(i - cnt, cnt);
                //cout << t<<endl;
                mp[t]++;
                cnt = 0;
                maxn = max(maxn, mp[t]);
            }
        }
    }
    //cout << maxn<<endl;
    for(auto it = mp.begin(); it != mp.end(); it++){
        //cout << it->first << it->second;
        if(it->second == maxn){
            cout << it->first << " " << it->second;
            return 0;
        }
    }
}
