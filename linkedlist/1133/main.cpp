#include <iostream>
#include <vector>

using namespace std;
struct Node{
    int data;
    int next;
}node[100005];

int main()
{
    int st, n, num, temp;
    scanf("%d %d %d", &st, &n, &num);
    vector<Node> cnt[3];
    for(int i = 0; i < n; i++){
        scanf("%d", &temp);
        scanf("%d %d", &node[temp].data, &node[temp].next);
    }
    for(int i = st; i != -1; i = node[i].next){
        if(node[i].data < 0) cnt[0].push_back(Node{node[i].data, i});
        else if(node[i].data >= 0 && node[i].data <= num) cnt[1].push_back(Node{node[i].data, i});
        else if(node[i].data > num) cnt[2].push_back(Node{node[i].data, i});
    }
    int ed;
    for(int i = 2; i >= 0; i--){
        if(cnt[i].size() != 0){
            ed = i;
            break;
        }
    }
    for(int i = 0; i <= ed; i++){
        for(int j = 0; j < cnt[i].size(); j++){
            if(j == cnt[i].size() - 1){
                if(i == ed){
                    printf("%05d %d -1\n", cnt[i][j].next, cnt[i][j].data);
                }else{
                    int temp = i + 1;
                    while(cnt[temp].size() == 0) temp++;
                    printf("%05d %d %05d\n", cnt[i][j].next, cnt[i][j].data, cnt[temp][0].next);
                }
            }else{
                printf("%05d %d %05d\n", cnt[i][j].next, cnt[i][j].data, cnt[i][j + 1].next);
            }
        }
    }
    return 0;
}
