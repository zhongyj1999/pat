#include <iostream>

using namespace std;

int main()
{
    int n;
    double a, ans = 0.0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lf", &a);
        ans += a * i * (n - i + 1);
    }
    printf("%.2f", ans);
    return 0;
}
