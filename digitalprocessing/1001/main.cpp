#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a, b;
    vector<int> v;
    scanf("%d %d", &a, &b);
    int ans = a + b;
    if(ans == 0) printf("0");
    if(ans < 0){
        printf("-");
        ans = - ans;
    }
    while(ans > 0){
        v.push_back(ans % 10);
        ans /= 10;
    }
    for(int i = v.size() - 1; i >= 0; i--){
        printf("%d", v[i]);
        if(i % 3 == 0 && i != 0) printf(",");
    }
    return 0;
}
