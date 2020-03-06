#include <iostream>

using namespace std;

int main()
{
    int c[3];
    string s = "0123456789ABC";
    scanf("%d %d %d", &c[0], &c[1], &c[2]);
    printf("#");
    for(int i = 0; i < 3; i++){
        printf("%c%c", s[c[i] / 13], s[c[i] % 13]);
    }
    return 0;
}
