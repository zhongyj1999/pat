#include <iostream>
using namespace std;
int main(){
    int k, have[256] = {0};
    bool exsit[256] = {false};
    scanf("%d", &k);
    string s;
    cin >> s;
    int cnt = 1;
    char pre = '*';
    for(int i = 0; i < s.length(); i++){
        if(s[i] == pre){
            cnt++;
            if(cnt % k == 0){
                have[s[i]] += k;
            }
        }else
            cnt = 1;
        pre = s[i];
        have[s[i]]--;
        //printf("%d %c %d\n", cnt, s[i], have[s[i]]);
    }
    for(int i = 0; i < s.length(); i++){
        if(have[s[i]] == 0){
            if(!exsit[s[i]]){
                printf("%c", s[i]);
                exsit[s[i]] = true;
            }
        }
    }
    printf("\n");
    for(int i = 0; i < s.length(); i++){
        printf("%c", s[i]);
        if(have[s[i]] == 0) i += k - 1;
    }
    return 0;
}
