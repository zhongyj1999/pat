#include <iostream>

using namespace std;

int main()
{
    string s = "WTL";
    double ans = 1.0;
    double a[4][4], b[4];
    for(int i = 0; i < 3; i++){
        double maxn = -1.0;
        for(int j = 0; j < 3; j++){
            scanf("%lf", &a[i][j]);
            if(a[i][j] > maxn){
                maxn = a[i][j];
                b[i] = j;
            }
        }
        ans *= maxn;
    }
    for(int i = 0; i < 3; i++)
        printf("%c ", s[b[i]]);
    printf("%.2f", (ans * 0.65 - 1) * 2.0);
    return 0;
}
