#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
vector<int> node[10];
queue<int> q, qi;
vector<int> level, in;
int root;

void levelorder(int root){
    q.push(root);
    while(!q.empty()){
        int top = q.front();
        int length = node[top].size();
        for(int i = length - 1; i >= 0; i--){
            if(node[top][i] != -1){
                q.push(node[top][i]);
                level.push_back(node[top][i]);
                //printf("%d\n", node[top][i]);
            }
        }
        q.pop();
    }
}

void inorder(int t){
    if(node[t].size() == 2){
        if(node[t][0] == -1){
            in.push_back(t);
            inorder(node[t][1]);
        }
        else{
            inorder(node[t][0]);
            in.push_back(t);
            inorder(node[t][1]);
        }
    }
    else if(node[t].size() == 1){
        inorder(node[t][0]);
        in.push_back(t);
    }
    else
        in.push_back(t);
}

int main()
{
    int n;
    scanf("%d", &n);
    //level.resize(n + 1);
    //in.resize(n + 1);
    for(int i = 0; i < n; i++){
        string s, t;
        int a, b;
        cin >> s >> t;
        if(s == "-"){
            if(t != "-"){
                b = stoi(t);
                node[i].push_back(-1);
                node[i].push_back(b);
            }
        }
        else{
            a = stoi(s);
            node[i].push_back(a);
            if(t != "-"){
                b = stoi(t);
                node[i].push_back(b);
            }
        }
        //cout << a << b <<endl;
    }
    for(int k = 0; k < n; k++){
        bool flag = true;
        for(int i = 0; i < n; i++){
            int l = node[i].size();
            //printf("%d\n", l);
            if(l > 0){
                for(int j = 0; j < l; j++){
                    //printf("%d %d\n", i, node[i][j]);
                    if(node[i][j] == k){
                        flag = false;
                    }
                }
            }
        }
        if(flag == true)
            root = k;
    }
    //printf("%d\n", root);
    levelorder(root);
    inorder(root);
    //printf("%d\n", level.size());
    printf("%d", root);
    for(int i = 0; i < level.size(); i++){
        printf(" %d", level[i]);
    }
    printf("\n");
    printf("%d", in[in.size() - 1]);
    for(int i = in.size() - 2; i >= 0; i--){
        printf(" %d", in[i]);
    }
    return 0;
}
