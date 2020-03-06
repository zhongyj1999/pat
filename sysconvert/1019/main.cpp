#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, radix;
    bool flag = true;
    vector<int> v;
    scanf("%d %d", &n, &radix);
    while(n > 0){
        v.push_back(n % radix);
        n /= radix;
    }
    vector<int> t(v);
    reverse(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++){
        if(v[i] != t[i]){
            flag = false;
            break;
        }
    }
    if(flag) printf("Yes\n");
    else printf("No\n");
    for(int i = 0; i < v.size(); i++){
        printf("%d", v[i]);
        if(i != v.size() - 1) printf(" ");
    }
    return 0;
}
