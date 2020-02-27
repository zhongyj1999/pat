#include <iostream>

using namespace std;

int hashFunc(int s){
    int id = 0;
    while(s >= 1){
        id += s % 10;
        s /= 10;
    }
    return id;
}

int main()
{
    int n, temp, cnt = 0;
    bool have[37] = {false};
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &temp);
        int id = hashFunc(temp);
        if(have[id] == false){
            have[id] = true;
            cnt++;
        }
    }
    printf("%d\n", cnt);
    for(int i = 1; i < 37; i++){
        if(have[i] == true){
            printf("%d", i);
            if(cnt-- > 1)
                printf(" ");
        }
    }
    return 0;
}
