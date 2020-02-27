#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;
int m, n, l, t;
int cnt = 0;
int arr[1300][130][80];
bool inq[1300][130][80] = {false};
int xt[6] = {1, -1, 0, 0, 0, 0};
int yt[6] = {0, 0, 1, -1, 0, 0};
int zt[6] = {0, 0, 0, 0, 1, -1};

struct node{
    int x;
    int y;
    int z;
};

bool judge(int x, int y, int z){
    if(x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= l) return false;
    if(arr[x][y][z] == 0 || inq[x][y][z] == true) return false;
    return true;
}

int BFS(int x, int y, int z){
    queue<node> q;
    node start;
    start.x = x;
    start.y = y;
    start.z = z;
    q.push(start);
    inq[x][y][z] = true;
    int num = 0;
    while(!q.empty()){
        node topnode = q.front();
        q.pop();
        num++;
        for(int i = 0; i < 6; i++){
            node next;
            next.x = topnode.x + xt[i];
            next.y = topnode.y + yt[i];
            next.z = topnode.z + zt[i];
            /*
            if(judge(next.x, next.y, next.z)){
                q.push(next);
                inq[next.x][next.y][next.z] = true;
            }
            */
            if(next.x >= 0 && next.y >= 0 && next.z >= 0 && next.x < m && next.y < n && next.z < l){
                if(arr[next.x][next.y][next.z] == 1 && inq[next.x][next.y][next.z] == false){
                    q.push(next);
                    inq[next.x][next.y][next.z] = true;
                }
            }
        }
    }
    if(num >= t)
        return num;
    else
        return 0;
}

void BFSTrave(){
    for(int i = 0; i< l; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < n; k++){
                if(arr[j][k][i] == 1 && inq[j][k][i] == false){
                    cnt += BFS(j, k, i);
                }
            }
        }
    }
}

int main()
{
    scanf("%d %d %d %d", &m, &n, &l, &t);
    for(int i = 0; i< l; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < n; k++){
                scanf("%d", &arr[j][k][i]);
            }
        }
    }
    BFSTrave();
    printf("%d", cnt);
    return 0;
}
