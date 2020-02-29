#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    double maxlength = 0;
    scanf("%d", &n);
    vector<int> loop(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &loop[i]);
    sort(loop.begin(), loop.end());
    maxlength += loop[0];
    for(int i = 1; i < n; i++){
        maxlength = (maxlength + loop[i]) / 2.0;
    }
    printf("%d", int(maxlength));
    return 0;
}
