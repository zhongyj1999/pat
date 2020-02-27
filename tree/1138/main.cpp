/*#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
vector<int> pre, in, post;
int n;

void postorder(int stpre, int edpre, int stin, int edin){
    if(stin > edin || stpre > edpre) return;
    int index = stin;
    while(in[index] != pre[stpre]) index++;
    if(index > edpre || index > edin) return;
    int root = index - stin;
    //printf("%d %d\n", root, index);
    //printf("%d %d %d %d\n", stpre + 1, stpre + root, stin, stin + root - 1);
    //printf("%d %d %d %d\n", stpre + root + 1, edpre, stin + root + 1, edin);
    postorder(stpre + 1, stpre + root, stin, stin + root - 1);
    postorder(stpre + root + 1, edpre, stin + root + 1, edin);
    post.push_back(in[index]);
}

int main()
{
    scanf("%d", &n);
    pre.resize(n);
    in.resize(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &pre[i]);
    }
    for(int i = 0; i< n; i++){
        scanf("%d", &in[i]);
    }
    postorder(0, n - 1, 0, n - 1);
    printf("%d", post[0]);
    for(int i = 0; i < n; i++){
        printf("%d ", post[i]);
    }
    return 0;
}*/
#include <iostream>
#include <vector>
using namespace std;
vector<int> pre, in;
bool flag = false;
void postOrder(int prel, int inl, int inr) {
    if (inl > inr || flag == true) return;
    int i = inl;
    while (in[i] != pre[prel]) i++;
    postOrder(prel+1, inl, i-1);
    postOrder(prel+i-inl+1, i+1, inr);
    if (flag == false) {
        printf("%d", in[i]);
        flag = true;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    pre.resize(n);
    in.resize(n);
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    postOrder(0, 0, n-1);
    return 0;
}
