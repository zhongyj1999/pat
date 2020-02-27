#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
const int MAXV = 205;
const int INF = 1000000000;
int n, k, st, ed, cnt = 1;
int G[MAXV][MAXV], d[MAXV], happy[MAXV];
bool vis[MAXV] = {false};
vector<int> pre[MAXV], path, tempPath;
map<string, int> stringToint;
map<int, string> intTostring;
int totalhappy = -1;
double averhappy = -1;
int numRoad = 0;

int sToi(string s){
    map<string, int>::iterator iter;
    iter = stringToint.find(s);
    if(iter != stringToint.end()){
        return stringToint[s];
    }
    else{
        intTostring[cnt] = s;
        stringToint[s] = cnt++;
        return stringToint[s];
    }
}

void Dijkstra(int s){
    fill(d, d + MAXV, INF);
    d[s] = 0;
    for(int i = 0; i < n; i++){
        int u = -1, MIN = INF;
        for(int j = 1; j <= n; j++){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 1; v <= n; v++){
            if(vis[v] == false && G[u][v] != INF){
                if(d[u] + G[u][v] < d[v]){
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if(d[u] + G[u][v] == d[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void DFS(int v){
    tempPath.push_back(v);
    if(v == st){
        numRoad++;
        int temptotal = 0;
        double tempaver;
        for(int i = tempPath.size() - 1; i >= 0; i--){
            int id = tempPath[i];
            temptotal += happy[id];
        }
        tempaver = 1.0 * temptotal / (tempPath.size() - 1);
        if(temptotal > totalhappy){
            totalhappy = temptotal;
            averhappy = tempaver;
            path = tempPath;
        } else if(temptotal == totalhappy && tempaver > averhappy){
            averhappy = tempaver;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    for(int i = 0; i < pre[v].size(); i++){
        DFS(pre[v][i]);
    }
    tempPath.pop_back();
}

int main()
{
    fill(G[0], G[0] + MAXV * MAXV, INF);
    string s, t;
    int h;
    cin >> n >> k >> s;
    //printf("%d %d\n", n, k);
    st = sToi(s);
    for(int i = 0; i < n -1; i++){
        cin >> t >> h;
        happy[sToi(t)] = h;
        //printf("%d %d\n", sToi(t), h);
    }
    int tempCost;
    for(int i = 0; i < k; i++){
        cin >> s >> t >> tempCost;
        int a = sToi(s);
        int b = sToi(t);
        G[a][b] = G[b][a] = tempCost;
        //printf("%d %d %d\n", a, b, tempCost);
    }
    ed = sToi("ROM");
    //printf("%d %d\n", st, ed);
    Dijkstra(st);
    DFS(ed);
    printf("%d %d %d %d\n", numRoad, d[ed], totalhappy, (int)averhappy);
    for(int i = path.size() - 1; i > 0; i--){
        //printf("%d\n", path[i]);
        cout << intTostring[path[i]] << "->";
        //printf("->%s", intTostring[path[i]]);
    }
    cout << "ROM";
    return 0;
}
