#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    bool flag[256] = {false};
    char s1[85], s2[85];
    scanf("%s %s", s1, s2);
    int l1 = strlen(s1), l2 = strlen(s2);
    for(int i = 0; i < l2; i++){
        flag[toupper(s2[i])] = true;
    }
    for(int i = 0; i < l1; i++){
        s1[i] = toupper(s1[i]);
        if(!flag[s1[i]]){
            printf("%c", toupper(s1[i]));
            flag[s1[i]] = true;
        }
    }
    return 0;
}
