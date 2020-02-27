#include <iostream>
#include <map>

using namespace std;
const int MAXN = 2010;
map<string, int> stringtoint;
map<int, string> inttostring;
map<string, int> ans;
int G[MAXN][MAXN];
int weight[MAXN];
bool vis[MAXN];
int idnumber = 1, k;

int sToifunc(string s){
    if(stringtoint[s] == 0){
        stringtoint[s] = idnumber;
        inttostring[idnumber] = s;
        return idnumber++;
    }
    else
        return stringtoint[s];
}

void DFS(int u, int &head, int &numpeople, int &totalweight){
    vis[u] = true;
    numpeople++;
    if(weight[u] > weight[head])
        head = u;
    for(int v = 1; v < idnumber; v++){
        if(G[u][v] > 0){
            totalweight += G[u][v];
            G[u][v] = G[v][u] = 0;
            if(vis[v] == false)
                DFS(v, head, numpeople, totalweight);
        }
    }
}

void DFSTrave(){
    for(int i = 1; i < idnumber; i++){
        if(vis[i] == false){
            int head = i, numpeople = 0, totalweight = 0;
            DFS(i, head, numpeople, totalweight);
            if(numpeople > 2 && totalweight > k)
            ans[inttostring[head]] = numpeople;
        }
    }
}



int main()
{
    int n, w;
    string s1, s2;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> s1 >> s2 >> w;
        int id1 = sToifunc(s1);
        int id2 = sToifunc(s2);
        weight[id1] += w;
        weight[id2] += w;
        G[id1][id2] += w;
        G[id2][id1] += w;
    }
    DFSTrave();
    cout << ans.size() << endl;
    for(auto it = ans.begin(); it != ans.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}
