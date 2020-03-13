#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
vector<int> level(40, 0);
int maxn = -1;
struct node{
    int v, height;
    node *lchild, *rchild;
};

node* newNode(int v){
    node* Node = new node;
    Node->v = v;
    Node->height = 1;
    Node->lchild = Node->rchild = NULL;
    return Node;
}

int getHeight(node* root){
    if(root == NULL) return 0;
    return root->height;
}

void updateHeight(node* root){
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

int getBalanceFactor(node* root){
    return getHeight(root->lchild) - getHeight(root->rchild);
}

void R(node* &root){
    node* temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void L(node* &root){
    node* temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void insert(node* &root, int v){
    if(root == NULL){
        root = newNode(v);
        return ;
    }
    if(v < root->v){
        insert(root->lchild, v);
        updateHeight(root);
        if(getBalanceFactor(root) == 2){
            if(getBalanceFactor(root->lchild) == 1){
                R(root);
            }else if(getBalanceFactor(root->lchild) == -1){
                L(root->lchild);
                R(root);
            }
        }
    }else{
        insert(root->rchild, v);
        updateHeight(root);
        if(getBalanceFactor(root) == -2){
            if(getBalanceFactor(root->rchild) == -1){
                L(root);
            }else if(getBalanceFactor(root->rchild) == 1){
                R(root->rchild);
                L(root);
            }
        }
    }
}

void levelorder(node* root, int index){
    if(root == NULL){
        return ;
    }
    level[index] = root->v;
    maxn = max(maxn, index);
    if(root->lchild != NULL){
        levelorder(root->lchild, index * 2 + 1);
    }
    if(root->rchild != NULL){
        levelorder(root->rchild, index * 2 + 2);
    }
}

node* Create(int data[], int n){
    node* root = NULL;
    for(int i = 0; i < n; i++){
        insert(root, data[i]);
    }
    return root;
}

int main()
{
    int n,temp;
    bool flag = true;
    scanf("%d", &n);
    int v[25];
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    node* root = Create(v, n);
    //printf("%d\n", root->v);
    levelorder(root, 0);
    for(int i = 0; i <= maxn; i++){
        if(level[i] == 0) flag = false;
        else{
            printf("%d", level[i]);
            if(i != maxn) printf(" ");
        }
    }
    if(flag) printf("\nYES\n");
    else printf("\nNO\n");
    return 0;
}
