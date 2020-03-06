#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s;
    string o[11] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    cin >> s;
    int ans = 0;
    for(int i = 0; i < s.length(); i++){
        ans += s[i] - '0';
    }
    if(ans == 0){
        printf("zero");
        return 0;
    }
    vector<int> a;
    while(ans > 0){
        a.push_back(ans % 10);
        //printf("%d\n", ans % 10);
        ans /= 10;
    }
    for(int i = a.size() - 1; i >= 0; i--){
        cout << o[a[i]];
        if(i != 0) printf(" ");
    }
    return 0;
}
