#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int n, root;
vector<int> tree[25], level, node;
bool vis[25];

void levelorder(int st, int index){
    level.push_back(index);
    node[index] = st;
    if(tree[st][0] != -1){
        levelorder(tree[st][0], 2 * index + 1);
    }
    if(tree[st][1] != -1){
        levelorder(tree[st][1], 2 * index + 2);
    }
}

int main()
{
    scanf("%d", &n);
    node.resize(n * 2);
    for(int i = 0; i < n; i++){
        string a, b;
        int temp;
        cin >> a >> b;
        //cout << a << b;
        if(a != "-"){
            vis[stoi(a)] = true;
            tree[i].push_back(stoi(a));
        } else if(a == "-"){
            tree[i].push_back(-1);
        }
        if(b != "-"){
            vis[stoi(b)] = true;
            tree[i].push_back(stoi(b));
        } else if(b == "-"){
            tree[i].push_back(-1);
        }
    }
    for(int i = 0; i < n; i++){
        if(vis[i] == false){
            root = i;
            //break;
        }
    }
    //cout << root;
    levelorder(root, 0);
    /*
    for(int i = 0; i < n; i++){
        printf("%d ", level[i]);
    }
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("%d ", node[i]);
    }
    printf("\n");
    */
    sort(level.begin(), level.end());
    for(int i = 0; i < n; i++){
        if(i != level[i]){
            printf("NO %d", root);
            return 0;
        }
    }
    printf("YES %d", node[n - 1]);
    return 0;
}
