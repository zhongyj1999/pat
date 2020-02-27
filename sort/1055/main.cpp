#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
struct node{
    string name;
    int age, worth;
};
int n, k;

bool cmp1(node a, node b){
    if(a.worth != b.worth)
        return a.worth > b.worth;
    else if(a.age != b.age)
        return a.age < b.age;
    else
        return a.name < b.name;
}

int main()
{
    scanf("%d %d", &n, &k);
    vector<node> peol, v;
    vector<int> book(205, 0);
    for(int i = 0; i < n; i++){
        string temp;
        int age, worth;
        cin >> temp;
        scanf("%d %d", &age, &worth);
        peol.push_back(node{temp, age, worth});
    }
    sort(peol.begin(), peol.end(), cmp1);
    for(int i = 0; i < n; i++){
        if(book[peol[i].age] < 100){
            v.push_back(peol[i]);
            book[peol[i].age]++;
        }
    }
    for(int i = 1; i <= k; i++){
        int m, amin, amax;
        bool flag = false;
        scanf("%d %d %d", &m, &amin, &amax);
        printf("Case #%d:\n", i);
        for(int j = 0; j < v.size(); j++){
            if(v[j].age >= amin && v[j].age <= amax && m > 0){
                cout << v[j].name;
                printf(" %d %d\n", v[j].age, v[j].worth);
                flag = true;
                m--;
            }
        }
        if(flag == false)
            printf("None\n");
    }
    return 0;
}
