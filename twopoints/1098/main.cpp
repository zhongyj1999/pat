#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, a[105], b[105];
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    int temp, ed;
    for(int i = 0; i < n - 1; i++){
        if(b[i + 1] < b[i]){
            temp = i + 1;
            break;
        }
    }
    for(ed = temp; ed < n; ed++){
        if(a[ed] != b[ed])
            break;
    }
    if(ed == n){
        printf("Insertion Sort\n");
        sort(b, b + temp + 1);
    } else{
        printf("Heap Sort\n");
        int heap = n - 1, maxn;
        for(int i = n - 1; i >= 0; i--){
            if(b[i] >= b[0]) heap--;
            else break;
        }
        swap(b[0], b[heap]);
        for(int i = 0; i <= heap / 2 - 1; i++){
            if(2 * i + 2 != heap){
                if(b[2 * i + 1] > b[2 * i + 2]) maxn = 2 * i + 1;
                else maxn = 2 * i + 2;
                if(b[maxn] > b[i]) swap(b[maxn], b[i]);
            } else{
                if(b[2 * i + 1] > b[i]) swap(b[2 * i + 1], b[i]);
            }
        }
    }
    for(int i = 0; i < n; i++){
        printf("%d", b[i]);
        if(i != n - 1) printf(" ");
    }
    return 0;
}
