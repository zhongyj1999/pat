#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n, num = 1;
    scanf("%d", &n);
    set<int> s;
    for(int i = 0; i < n; i++){
        int temp;
        scanf("%d", &temp);
        if(temp > 0) s.insert(temp);
    }
    for(int i = 1; i <= s.size(); i++){
        set<int>::iterator it = s.find(i);
        if(it == s.end()){
            printf("%d", i);
            return 0;
        }
    }
    if(s.size() == 0)
        printf("1");
    else
        printf("%d", s.size() + 1);
    return 0;
}
