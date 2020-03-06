#include <iostream>
#include <vector>

using namespace std;
struct node{
    string username, password;
};

int main()
{
    int n;
    scanf("%d", &n);
    vector<node> v;
    for(int i = 0; i < n; i++){
        string s, t;
        cin >> s >> t;
        string temp(t);
        for(int j = 0; j < t.length(); j++){
            if(t[j] == '1') t[j] = '@';
            else if(t[j] == '0') t[j] = '%';
            else if(t[j] == 'l') t[j] = 'L';
            else if(t[j] == 'O') t[j] = 'o';
        }
        if(t != temp) v.push_back(node{s, t});
    }
    if(v.size() == 0){
        if(n == 1)
            printf("There is 1 account and no account is modified\n");
        else
            printf("There are %d accounts and no account is modified\n", n);
    }else{
        printf("%d\n", v.size());
        for(int i = 0; i < v.size(); i++){
            cout << v[i].username << " " << v[i].password <<endl;
        }
    }
    return 0;
}
