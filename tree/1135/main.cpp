
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
vector<int> arr;
struct node{
    int val;
    struct node *left, *right;
};

node* build(node *root, int v){
    if(root == NULL){
        root = new node();
        root->val = v;
        root->left = root->right = NULL;
    } else if(abs(v) <= abs(root->val)){
        root->left = build(root->left, v);
    } else{
        root->right = build(root->right, v);
    }
    return root;
}

bool judge1(node *root){
    if(root == NULL) return true;
    if(root->val < 0){
        if(root->left != NULL && root->left->val < 0) return false;
        if(root->right != NULL && root->right->val < 0) return false;
    }
    return judge1(root->left) && judge1(root->right);
}

int getnum(node *root){
    if(root == NULL) return 0;
    int l = getnum(root->left);
    int r = getnum(root->right);
    return root->val > 0 ? max(l, r) + 1 : max(l, r);
}

bool judge2(node *root){
    if(root == NULL) return true;
    int l = getnum(root->left);
    int r = getnum(root->right);
    if(l != r) return false;
    return judge2(root->left) && judge2(root->right);
}

int main(){
    int k, n;
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        scanf("%d", &n);
        arr.resize(n);
        node *root = NULL;
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[j]);
            root = build(root, arr[j]);
        }
        if(arr[0] < 0 || judge1(root) == false || judge2(root) == false)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}


/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int k, n, numblack;
vector<int> num, pre[30];
bool flag = false;

void inorder(int i, int stpre, int edpre, int numb, int sign){
    if(stpre >= edpre){
        return ;
    }
    int index = stpre + 1;
    while(abs(pre[i][index]) < abs(pre[i][stpre])){
        index++;
        if(index >= edpre){
            index = edpre;
            break;
        }
    }
    if(sign == -1){
        if(pre[i][stpre] < 0)
            flag = true;
    }
    if(pre[i][stpre] > 0){
        sign = 1;
        numb++;
    }
    else if(pre[i][stpre] < 0){
        sign = -1;

    }
    printf("%d %d %d %d %d\n", index, pre[i][index], stpre, edpre, numb);
    inorder(i, stpre, index - 1, numb, sign);
    inorder(i, index + 1, edpre, numb, sign);
}

int main()
{
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        scanf("%d", &n);
        pre[i].resize(n);
        for(int j = 0; j < n; j++){
            scanf("%d", &pre[i][j]);
            if(pre[i][j] == 0){
                printf("NO\n");
                break;
            }
            if(pre[i][0] < 0){
                printf("NO\n");
                break;
            }
        }
        inorder(i, 1, n - 1, 0, 1);
        for(int i = 0; i < num.size(); i++){
            cout << num[i] << " ";
        }
        if(flag == false){
            printf("YES\n");
        }
        else if(flag == true){
            printf("NO\n");
            flag = false;
        }
        num.clear();
    }
    return 0;
}
*/
