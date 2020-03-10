#include <iostream>
#include <vector>

using namespace std;
int n, m, flag = 0;
vector<int> level, post;

void postorder(int st){
    if(2 * st + 1 < m){
        if(level[st] > level[2 * st + 1]) flag++;
        else flag--;
        postorder(2 * st + 1);
    }
    if(2 * st + 2 < m){
        if(level[st] > level[2 * st + 1]) flag++;
        else flag--;
        postorder(2 * st + 2);
    }
    post.push_back(level[st]);
}

int main()
{
    scanf("%d %d", &n, &m);
    level.resize(m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &level[j]);
        }
        postorder(0);
        //printf("%d %d\n", flag, post.size());
        if(flag == m - 1) printf("Max Heap\n");
        else if(flag == 1 - m) printf("Min Heap\n");
        else printf("Not Heap\n");
        for(int k = 0; k < post.size(); k++){
            printf("%d", post[k]);
            if(k != post.size() - 1) printf(" ");
            else
                if(i != n - 1) printf("\n");
        }
        flag = 0;
        post.clear();
    }
    return 0;
}
