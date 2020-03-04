#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n, m, num, temp;
    scanf("%d %d %d", &n, &m, &num);
    stack<int> s;
    for(int i = 0; i < num; i++){
        bool flag = true;
        int j, k = 1;
        for(j = 1; j <= m; j++){
            scanf("%d", &temp);
            if(temp >= k){
                for(; k <= temp; k++)
                    s.push(k);
                int se = s.size();
                if(se > n){
                    flag = false;
                }
            }
            int a = s.top();
            //cout << a<<endl;
            if(a != temp) flag = false;
            s.pop();
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
        while(!s.empty())
            s.pop();
    }
    return 0;
}
