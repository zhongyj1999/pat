#include <iostream>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;
vector<int> pre, in, post, value;

void postorder(int root, int start, int end){
    if(start > end) return;
    int i = start;
    while(i < end && in[i] != pre[root]) i++;
    postorder(root + 1, start, i - 1);
    postorder(root + 1 + i - start, i + 1, end);
    post.push_back(pre[root]);
}

int main()
{
    int n;
    scanf("%d", &n);
    string t;
    stack<int> s;
    int m, cnt = 0;
    for(int i = 1; i <= 2 * n; i++){
        cin >> t;
        if(t == "Push"){
            scanf("%d", &m);
            value.push_back(m);
            pre.push_back(cnt);
            s.push(cnt++);
        } else{
            in.push_back(s.top());
            s.pop();
        }
    }
    postorder(0, 0, n - 1);
    printf("%d", value[post[0]]);
    for(int i = 1; i < n; i++){
        printf(" %d", value[post[i]]);
    }
    return 0;
}
