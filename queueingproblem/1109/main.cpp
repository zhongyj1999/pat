#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct node{
    string name;
    int height, row, rank;
};

bool cmp1(node a, node b){
    if(a.height != b.height)
        return a.height < b.height;
    else
        return a.name > b.name;
}

bool cmp2(node a, node b){
    if(a.row != b.row)
        return a.row < b.row;
    else
        return a.rank < b.rank;
}

int main()
{
    int n, row;
    scanf("%d %d", &n, &row);
    int num = n / row;
    vector<node> people(n);
    vector<int> r(row, num);
    r[row - 1] += n % row;
    for(int i = 0; i < n; i++){
        cin >> people[i].name >> people[i].height;
    }
    sort(people.begin(), people.end(), cmp1);
    for(int i = row - 1; i >= 0; i--){
        int left, right;
        left = right = r[i] / 2;
        bool flag = true;
        for(int j = i * num + r[i] - 1; j >= i * num; j--){
            //cout << left << right << j <<endl;
            people[j].row = i;
            if(left == right){
                people[j].rank = left--;
                right++;
            }else if(flag){
                people[j].rank = left--;
                flag = false;
            }else{
                people[j].rank = right++;
                flag = true;
            }
        }
    }
    sort(people.begin(), people.end(), cmp2);
    for(int i = row - 1; i >= 0; i--){
        for(int j = i * num; j <= i * num + r[i] - 1; j++){
            cout << people[j].name;
            if(j != i * num + r[i] - 1) printf(" ");
            else if(i != 0)printf("\n");
        }
    }
    return 0;
}
