#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int l = s.length();
        int a = stoi(s.substr(0, l / 2));
        int b = stoi(s.substr(l / 2));
        if(a == 0 || b == 0) printf("No\n");
        else if((stoi(s) % (a * b)) == 0) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
