#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
struct node{
    int data, index;
};
vector<int> post, in;
vector<node> level;

bool cmp1(node a, node b){
    return a.index < b.index;
}

void levelorder(int postpre, int inpre, int intail, int index){
    if(inpre > intail) return ;
    int temp = inpre;
    while(temp < intail && post[postpre] != in[temp]) temp++;
    level.push_back(node{in[temp], index});
    //printf("%d %d %d %d %d\n", postpre, inpre, intail, index, temp);
    levelorder(postpre - intail + temp - 1, inpre, temp - 1, 2 * index + 1);
    levelorder(postpre - 1, temp + 1, intail, 2 * index + 2);
}

int main()
{
    int n, k;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &k);
        post.push_back(k);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &k);
        in.push_back(k);
    }
    levelorder(n - 1, 0, n - 1, 0);
    sort(level.begin(), level.end(), cmp1);
    for(int i = 0; i < n; i++){
        printf("%d", level[i].data);
        if(i != n - 1) printf(" ");
    }
    return 0;
}
