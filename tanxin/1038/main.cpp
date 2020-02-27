#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool cmp(string a, string b){
    string s1 = a + b;
    string s2 = b + a;
    return s1 < s2;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<string> num;
    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        num.push_back(temp);
    }
    sort(num.begin(), num.end(), cmp);
    bool flag = false;
    for(int i = 0; i < n; i++){
        if(i == 0 || flag){
            int z = stoi(num[i]);
            if(z != 0){
                printf("%d", z);
                flag = false;
            }
            else
                flag = true;
        }
        else
            printf("%s", num[i].c_str());
    }
    if(flag)
        printf("0");
    return 0;
}
