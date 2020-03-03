#include <iostream>
#include <string>

using namespace std;

bool isprim(int a){
    if(a == 1 || a == 0) return false;
    for(int i = 2; i * i <= a; i++)
        if(a % i == 0) return false;
    return true;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    string s;
    cin >> s;
    for(int i = 0; i <= n - m; i++){
        string temp = s.substr(i, m);
        //cout << temp <<endl;
        int ans = stoi(temp);
        //cout << ans<<endl;
        if(isprim(ans)){
            cout << temp;
            return 0;
        }
    }
    printf("404\n");
    return 0;
}
