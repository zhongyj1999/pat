#include <iostream>
#include <map>

using namespace std;
map<int, int> mp;

int main()
{
    int n, m, temp, maxn = -1;
    scanf("%d %d", &n, &m);
    int half = m * n / 2;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &temp);
            mp[temp]++;
            if(mp[temp] > half){
                printf("%d", temp);
                return 0;
            }
        }
    }
}
