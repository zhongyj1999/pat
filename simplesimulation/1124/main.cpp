#include <iostream>
#include <vector>
#include <map>

using namespace std;
vector<string> pel;
map<string, bool> mp;

int main()
{
    int n, index, st;
    scanf("%d %d %d", &n, &index, &st);
    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        pel.push_back(temp);
    }
    if(st > pel.size()){
        printf("Keep going...\n");
    }else{
        for(st -= 1; st < pel.size(); st += index){
            while(mp[pel[st]] == true) st++;
            if(st >= pel.size()) break;
            cout << pel[st] <<endl;
            mp[pel[st]] = true;
        }
    }
    return 0;
}
