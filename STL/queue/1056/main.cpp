/*
At first, my idea was correct, but I just focus on queue too much in
order to lead me to a wrong direction. I didn't use a appropriate structure
to realize the storage of data.
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
struct node{
    int weight, index, rank, index0;
};
bool cmp1(node a, node b){
    return a.index0 < b.index0;
}

int main(){
    int n, g, num;
    scanf("%d %d", &n, &g);
    vector<int> v(n);
    vector<node> w(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    for(int i = 0; i < n; i++){
        scanf("%d", &num);
        w[i].weight = v[num];
        w[i].index = i;
        w[i].index0 = num;
    }
    queue<node> q;
    for(int i = 0; i < n; i++)
        q.push(w[i]);
    while(!q.empty()){
        int size = q.size();
        if(size == 1){
            node temp = q.front();
            w[temp.index].rank = 1;
            break;
        }
        int group = size / g;
        if(size % g != 0)
            group += 1;
        node maxnode;
        int maxn = -1, cnt = 0;
        for(int i = 0; i < size; i++){
            node temp = q.front();
            w[temp.index].rank = group + 1;
            q.pop();
            cnt++;
            if(temp.weight > maxn){
                maxn = temp.weight;
                maxnode = temp;
            }
            if(cnt == g || i == size - 1){
                cnt = 0;
                maxn = -1;
                q.push(maxnode);
            }
        }
    }
    sort(w.begin(), w.end(), cmp1);
    for(int i = 0; i < n; i++){
        if(i != 0) printf(" ");
        printf("%d", w[i].rank);
    }
    return 0;
}

/*
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int have[100000000];

int main()
{
    int n, m;
    queue<int> q;
    scanf("%d %d", &n, &m);
    vector<int> v(n), num(n), ans, a(n), b(n), l(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
        printf("%d ", v[i]);
    }
    for(int i = 0; i < n; i++){
        int temp;
        scanf("%d", &temp);
        q.push(v[temp]);
        printf("%d ", v[temp]);
    }
    printf("\n");
    int cnt = 1;
    a[cnt] = n / m;
    b[cnt] = n % m;
    l[cnt] = b[cnt] == 0 ? a[cnt] : a[cnt] + 1;
    while(1){
        if(a[cnt] == 1 && b[cnt] == 0) break;
        num[cnt] = b[cnt] == 0 ? a[cnt] * 2 : a[cnt] * 2 + b[cnt] - 1;
        printf("%d %d %d %d %d\n", a[cnt], b[cnt], l[cnt], cnt, num[cnt]);
        cnt++;
        a[cnt] = l[cnt - 1] / m;
        b[cnt] = l[cnt - 1] % m;
        l[cnt] = b[cnt] == 0 ? a[cnt] : a[cnt] + 1;
        if(a[cnt] == 0 && b[cnt] == 1){
            num[cnt] = 1;
            printf("%d %d %d %d %d\n", a[cnt], b[cnt], l[cnt], cnt, num[cnt]);
            break;
        }
    }
    int k = n - num[1] + 1;
    for(int i = 1; i <= cnt; i++){
        if(i != 1) k -= num[i];
        printf("%d\n", k);
        for(int j = 1; j <= l[i]; j++){
            if(j <= a[i]){
                for(int k = 0; k < m; k++){
                    ans.push_back(q.front());
                    q.pop();
                }
            }else if(b[i] > 0){
                for(int k = 0; k < b[i]; k++){
                    ans.push_back(q.front());
                    q.pop();
                }
            }
            sort(ans.begin(), ans.end());
            q.push(ans[ans.size() - 1]);
            ans.pop_back();
            for(int j = 0; j < ans.size(); j++){
                have[ans[j]] = k;
                printf("%d %d\n", ans[j], have[ans[j]]);
            }
            ans.clear();
        }
        if(i == cnt)
            have[q.front()] = k;
    }
    for(int i = 0; i < n; i++){
        printf("%d", have[v[i]]);
        if(i != n - 1) printf(" ");
    }
    return 0;
}
*/
