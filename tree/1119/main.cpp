#include <iostream>
#include <vector>

using namespace std;
vector<int> pre, post, in;
bool flag = true;

void inorder(int st, int ed, int s, int p){
    if(st > ed) return ;
    if(st == ed){
        in.push_back(pre[st]);
        return ;
    }
    int index = st + 1;
    while(post[p - 1] != pre[index]) index++;
    if(index - st - 2 < 0) flag = false;
    else inorder(st + 1, index - 1, s, s + index - st - 2);
    in.push_back(pre[st]);
    inorder(index, ed, s + index - st - 1, p - 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    pre.resize(n);
    post.resize(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &pre[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &post[i]);
    }
    inorder(0, n - 1, 0, n - 1);
    if(flag) printf("Yes\n");
    else printf("No\n");
    for(int i = 0; i < n; i++){
        printf("%d", in[i]);
        if(i != n - 1) printf(" ");
        else printf("\n");
    }
    return 0;
}
