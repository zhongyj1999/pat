#include <cstdio>
#include <vector>

using namespace std;
struct node{
    int data;
    node *left, *right;
};

void insertt(node* &root, int data){
    if(root == NULL){
        root = new node;
        root->data = data;
        root->left = root->right = NULL;
        return;
    }
    if(data < root->data) insertt(root->left, data);
    else insertt(root->right, data);
}

void preOrder(node* root, vector<int>&vi){
    if(root == NULL) return;
    vi.push_back(root->data);
    preOrder(root->left, vi);
    preOrder(root->right, vi);
}

void preOrderMirror(node* root, vector<int>&vi){
    if(root == NULL) return;
    vi.push_back(root->data);
    preOrderMirror(root->right, vi);
    preOrderMirror(root->left, vi);
}

void postOrder(node* root, vector<int>&vi){
    if(root == NULL) return;
    postOrder(root->left, vi);
    postOrder(root->right, vi);
    vi.push_back(root->data);
}

void postOrderMirror(node* root, vector<int>&vi){
    if(root == NULL) return;
    postOrderMirror(root->right, vi);
    postOrderMirror(root->left, vi);
    vi.push_back(root->data);
}

vector<int>origin, pre, preM, post, postM;
int main(){
    int n, data;
    node* root = NULL;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &data);
        origin.push_back(data);
        insertt(root, data);
    }
    preOrder(root, pre);
    preOrderMirror(root, preM);
    postOrder(root, post);
    postOrderMirror(root, postM);
    if(origin == pre){
        printf("YES\n");
        for(int i = 0; i < post.size(); i++){
            printf("%d", post[i]);
            if(i < post.size() - 1) printf(" ");
        }
    } else if(origin == preM){
        printf("YES\n");
        for(int i = 0; i < postM.size(); i++){
            printf("%d", postM[i]);
            if(i < postM.size() - 1) printf(" ");
        }
    } else{
        printf("NO\n");
    }
    return 0;
}

/*
int n;
vector<int> node, pre, mirror, postpre, postmirror, in;

void findroot(int st, int ed, int index){
    int root;
    if(st <= ed){
        int layer = log(ed - st + 1)/log(2);
        if(st == ed - 1) layer = 1;
        int num = pow(2, layer);
        int l = ed - st + 2 - 3 * pow(2, layer - 1);
        if(l <= 0){
            root = num + l + st - 1;
        }
        else{
            root = num + st - 1;
        }
        if(index == 0){
        pre.push_back(in[root]);
        findroot(st, root -1, 0);
        findroot(root + 1, ed, 0);
        postpre.push_back(in[root]);
        }
        if(index == 1){
        mirror.push_back(in[root]);
        findroot(root + 1, ed, 1);
        findroot(st, root -1, 1);
        postmirror.push_back(in[root]);
        }
    }
}

int main()
{
    scanf("%d", &n);
    node.resize(n);
    in.resize(n);
    //int i = log(3)/log(2);
    //printf("%d\n", i);
    for(int i = 0; i < n; i++){
        scanf("%d", &node[i]);
        in[i] = node[i];
    }
    sort(in.begin(), in.end());
    findroot(0, n - 1, 0);
    findroot(0, n - 1, 1);
    if(node != pre && node != mirror){
        printf("NO");
    }
    else if(node == pre){
        printf("YES\n%d", postpre[0]);
        for(int i = 1; i < n; i++){
            printf(" %d", postpre[i]);
        }
    }
    else if(node == mirror){
        printf("YES\n%d", postmirror[0]);
        for(int i = 1; i < n; i++){
            printf(" %d", postmirror[i]);
        }
    }
    return 0;
}
*/
