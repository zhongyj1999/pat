#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int flag[256] = {0}, cnt = 0;
    bool f = true;
    char s1[1005], s2[1005];
    scanf("%s %s", s1, s2);
    int l1 = strlen(s1), l2 = strlen(s2);
    for(int i = 0; i < l1; i++){
        flag[s1[i]]++;
    }
    for(int i = 0; i < l2; i++){
        flag[s2[i]]--;
        if(flag[s2[i]] < 0){
            cnt++;
            f = false;
        }
    }
    if(f == true)
        printf("Yes %d", l1 - l2);
    else
        printf("No %d", cnt);
    return 0;
}
