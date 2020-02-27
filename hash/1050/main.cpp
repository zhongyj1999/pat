#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <vector>

using namespace std;
map<string, bool> mp;
vector<string> s;

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    for(int i = 0; i < s2.size(); i++){
        mp[s2.substr(i, 1)] = true;
        //cout << s2.substr(i, 1) << mp[s2.substr(i, 1)]<<endl;
    }
    for(int i = 0; i < s1.size(); i++){
        if(mp[s1.substr(i, 1)] == false)
            s.push_back(s1.substr(i, 1));
    }
    for(int i = 0; i < s.size(); i++){
        printf("%s", s[i].c_str());
        //printf("%d", s[i].c_str());
    }
        //printf("%s", s[i].c_str());
    //cout << s1[0] <<s2.size()<< s2[0];
    return 0;
}
