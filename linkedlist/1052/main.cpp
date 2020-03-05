#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Node{
    int id;
    int data;
    int next;
}node[100005];

bool cmp1(Node a, Node b){
    return a.data < b.data;
}

int main()
{
    int n, st;
    vector<Node> ans;
    scanf("%d %d", &n, &st);
    for(int i = 0; i < n; i++){
        int temp;
        scanf("%d", &temp);
        node[temp].id = temp;
        scanf("%d %d", &node[temp].data, &node[temp].next);
    }
    for(int i = st; i != -1; i = node[i].next){
        ans.push_back(node[i]);
    }
    if(ans.size() == 0){
        printf("0 -1");
        return 0;
    }
    sort(ans.begin(), ans.end(), cmp1);
    printf("%d %05d\n", ans.size(), ans[0].id);
    for(int i = 0; i < ans.size(); i++){
        if(i == ans.size() - 1){
            printf("%05d %d -1\n", ans[i].id, ans[i].data);
        }else{
            printf("%05d %d %05d\n", ans[i].id, ans[i].data, ans[i + 1].id);
        }
    }
    return 0;
}
