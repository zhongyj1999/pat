#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int nc, np, temp;
    vector<int> cn, cp, pn, pp;
    scanf("%d", &nc);
    for(int i = 0; i < nc; i++){
        scanf("%d", &temp);
        if(temp > 0) cn.push_back(temp);
        else cp.push_back(temp);
    }
    scanf("%d", &np);
    for(int i = 0; i < np; i++){
        scanf("%d", &temp);
        if(temp > 0) pn.push_back(temp);
        else pp.push_back(temp);
    }
    int total = 0;
    int l1 = min(cn.size(), pn.size());
    int l2 = min(cp.size(), pp.size());
    sort(cn.begin(), cn.end(), greater<int>());
    sort(cp.begin(), cp.end());
    sort(pn.begin(), pn.end(), greater<int>());
    sort(pp.begin(), pp.end());
    for(int i = 0; i < l1; i++){
        total +=  cn[i] * pn[i];
    }
    for(int i = 0; i < l2; i++){
        total += cp[i] * pp[i];
    }
    printf("%d", total);
    return 0;
}
