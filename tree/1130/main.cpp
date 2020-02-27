#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;
vector<int> node[25];
vector<string> tree;
bool have[25];
int r;

void inorder(int root, int depth){
    if(node[root][0] != -1 && node[root][1] != -1){
        if(root != r) cout << "(";
        inorder(node[root][0], depth + 1);
        cout << tree[root - 1];
        inorder(node[root][1], depth + 1);
        if(root != r) cout << ")";
    }
    else if(node[root][0] != -1){
        if(root != r) cout << "(";
        inorder(node[root][0], depth + 1);
        cout << tree[root - 1];
        if(root != r) cout << ")";
    }
    else if(node[root][1] != -1){
        if(root != r) cout << "(";
        cout << tree[root - 1];
        inorder(node[root][1], depth + 1);
        if(root != r) cout << ")";
    }
    else{
        //if(depth > 1) cout << "(";
        cout << tree[root - 1];
        //if(depth > 1) cout << ")";
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    string a, b, c;
    for(int i = 1; i <= n; i++){
        cin >> a >> b >> c;
        tree.push_back(a);
        node[i].push_back(stoi(b));
        node[i].push_back(stoi(c));
        if(stoi(b) != -1)
            have[stoi(b)] = true;
        if(stoi(c) != -1)
            have[stoi(c)] = true;
        //cout << tree[i - 1] <<endl;
        //printf("%d %d %d\n", i, node[i][0], node[i][1]);
    }
    for(int i = 1; i <= n; i++){
        if(have[i] == false){
            r = i;
            break;
        }
    }
    //printf("%d\n", root);
    inorder(r, 0);
    return 0;
}
