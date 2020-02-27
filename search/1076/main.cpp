#include <cstdio>
#include <queue>
#include <vector>

using namespace std;
const int MAXV = 1010;
vector<vector<int>> people;

struct Node{
    int id;
    int layer;
};

int BFS(Node tnode, int l){
    bool inq[MAXV] = {false};
    int cnt = 0;
    queue<Node> q;
    q.push(tnode);
    inq[tnode.id] = true;
    while(!q.empty()){
        Node top = q.front();
        q.pop();
        int topid = top.id;
        for(int i = 0; i < people[topid].size(); i++){
            int nextid = people[topid][i];
            if(inq[nextid] == false && top.layer < l){
                Node next = {nextid, top.layer + 1};
                q.push(next);
                inq[next.id] = true;
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    int n, L, idFollow, numFollow;
    scanf("%d %d", &n, &L);
    people.resize(n + 1);
    for(int i = 1; i <= n; i++){
        scanf("%d", &numFollow);
        for(int j = 0; j < numFollow; j++){
            scanf("%d", &idFollow);
            people[idFollow].push_back(i);
        }
    }
    int k, userid;
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        scanf("%d", &userid);
        Node tnode = {userid, 0};
        printf("%d\n", BFS(tnode, L));
    }
}
