#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;
const int MAXV = 35;
int N[MAXV];

struct node{
    int data;
    node* lchild;
    node* rchild;
};

node* newNode(int v){
    node* Node = new node;
    Node -> data = v;
    Node -> lchild = Node -> rchild = NULL;
    return Node;
}

void insert(node* &root, int x){
    if(root == NULL){
        root = newNode(x);
        return;
    }
    if(root -> lchild == NULL){
        insert(root -> lchild, x);
    } else{
        insert(root -> rchild, x);
    }
}

void preorder(node* root){
    if(root == NULL){
        return;
    }
    printf("%d ", root -> data);
    preorder(root -> lchild);
    preorder(root -> rchild);
}

int main()
{
    int n;
    int cnt = 1;
    scanf("%d", &n);
    for(int i = 1; i <= 2 * n; i++){
        string s;
        int m;
        cin >> s;
        if(s == "Push"){
            scanf("%d", &m);
            insert(N[cnt], m);
            N[cnt++] = m;
        } else{
            cnt--;
        }
    }
    preorder(N[1]);
    return 0;
}
