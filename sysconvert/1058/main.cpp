#include <iostream>

using namespace std;

int main()
{
    int a[3], b[3], c[3] = {0};
    int cnt[] = {29, 17, 1};
    scanf("%d.%d.%d %d.%d.%d", &a[2], &a[1], &a[0], &b[2], &b[1], &b[0]);
    int carry = 0;
    for(int i = 0; i < 3; i++){
        carry = carry + a[i] + b[i];
        c[i] = carry % cnt[i];
        carry /= cnt[i];
    }
    for(int i = 2; i >= 0; i--){
        if(i == 2) printf("%d", carry);
        else printf("%d", c[i]);
        if(i != 0) printf(".");
    }
    return 0;
}
