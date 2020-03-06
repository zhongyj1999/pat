#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string s = "SHCDJ";
    int n, temp;
    scanf("%d", &n);
    vector<int> a(55), b(55);
    for(int i = 1; i < 55; i++){
        a[i] = i;
        scanf("%d", &temp);
        b[i] = temp;
    }
    for(int i = 0; i < n; i++){
        vector<int> temp(a);
        for(int j = 1; j < 55; j++){
            a[b[j]] = temp[j];
        }
    }
    for(int i = 1; i < 55; i++){
        //printf("%d", a[i]);
        if(a[i] % 13 == 0){
            printf("%c13", s[(a[i] / 13) - 1]);
        }else
            printf("%c%d", s[a[i] / 13], a[i] % 13);
        if(i != 54) printf(" ");
    }
    return 0;
}
