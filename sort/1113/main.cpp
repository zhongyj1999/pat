#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());
    int nn = n % 2;
    int total = 0;
    for(int i = 0; i < n; i++){
        if(i < n / 2)
            total -= a[i];
        else
            total += a[i];
    }
    printf("%d %d", nn, total);
    return 0;
}
