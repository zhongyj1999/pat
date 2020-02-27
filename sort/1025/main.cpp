#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
struct node {
    string id;
    int score, frank, lnum, lrank;
};
vector<node> test;
vector<int> k;

bool cmp1(node a, node b){
    if(a.lnum == b.lnum){
        if(a.score == b.score)
            return a.id < b.id;
        else
            return a.score > b. score;
    }else
        return a.lnum > b.lnum;
}

bool cmp2(node a, node b){
    if(a.score == b.score)
        return a.id < b.id;
    else
        return a.score > b. score;
}

int main()
{
    int n, num = 0;
    scanf("%d", &n);
    k.resize(n + 1);
    for(int i = 1; i <= n; i++){
        scanf("%d", &k[i]);
        vector<node> fi;
        for(int j = 0; j < k[i]; j++){
            string temp;
            int s;
            cin >> temp >> s;
            fi.push_back(node{temp, s, 0, i, 0});
        }
        num += k[i];
        sort(fi.begin(), fi.end(), cmp1);
        int cnt = 1;
        fi[0].lrank = cnt;
        test.push_back(fi[0]);
        for(int m = 1; m < k[i]; m++){
            if(fi[m].score == fi[m - 1].score){
                fi[m].lrank = fi[m - 1].lrank;
                cnt++;
                test.push_back(fi[m]);
            }else{
                fi[m].lrank = ++cnt;
                test.push_back(fi[m]);
            }
        }
    }
    sort(test.begin(), test.end(), cmp2);
    int cnt = 1;
    test[0].frank = cnt;
    for(int i = 1; i < test.size(); i++){
        if(test[i].score == test[i - 1].score){
            test[i].frank = test[i - 1].frank;
            cnt++;
        }else{
            test[i].frank = ++cnt;
        }
    }
    printf("%d\n", num);
    for(int i = 0; i < num; i++){
        cout << test[i].id;
        printf(" %d %d %d\n", test[i].frank, test[i].lnum, test[i].lrank);
    }

    return 0;
}
