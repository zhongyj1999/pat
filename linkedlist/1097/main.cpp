#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
struct Node{
    int id, data, next;
}node[100005];

map<int, bool> mp;

int main()
{
    int st, n;
    scanf("%d %d", &st, &n);
    vector<Node> ans, ree;
    for(int i = 0; i < n; i++){
        int temp;
        scanf("%d", &temp);
        node[temp].id = temp;
        scanf("%d %d", &node[temp].data, &node[temp].next);
    }
    for(int i = st; i != -1; i = node[i].next){
        if(mp[abs(node[i].data)] == false){
            ans.push_back(node[i]);
            mp[abs(node[i].data)] = true;
        }else{
            ree.push_back(node[i]);
        }
    }
    for(int i = 0; i < ans.size(); i++){
        if(i == ans.size() - 1){
            printf("%05d %d -1\n", ans[i].id, ans[i].data);
        }else{
            printf("%05d %d %05d\n", ans[i].id, ans[i].data, ans[i + 1].id);
        }
    }
    for(int i = 0; i < ree.size(); i++){
        if(i == ree.size() - 1){
            printf("%05d %d -1\n", ree[i].id, ree[i].data);
        }else{
            printf("%05d %d %05d\n", ree[i].id, ree[i].data, ree[i + 1].id);
        }
    }
    return 0;
}
