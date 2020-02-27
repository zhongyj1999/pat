#include <iostream>
#include <vector>
using namespace std;
bool isprim(int num){
    for(int i = 2; i * i <= num; i++)
        if(num % i == 0) return false;
    return true;
}
int main()
{
    int tsize, n, m, a;
    scanf("%d %d %d", &tsize, &n, &m);
    while(!isprim(tsize)) tsize++;
    vector<int> hasht(tsize);
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        int flag = 0;
        for(int j = 0; j < tsize; j++){
            int pos = (a + j * j) % tsize;
            if(hasht[pos] == 0){
                hasht[pos] = a;
                flag = 1;
                break;
            }
        }
        if(!flag) printf("%d cannot be inserted.\n", a);
     }
     int ans = 0;
     for(int i = 0; i < m; i++){
        scanf("%d", &a);
        for(int j = 0; j <= tsize; j++){
            ans++;
            int pos = (a + j * j) % tsize;
            if(hasht[pos] == a || hasht[pos] == 0) break;
        }
     }
     printf("%.1f", ans * 1.0 / m);
    return 0;
}
