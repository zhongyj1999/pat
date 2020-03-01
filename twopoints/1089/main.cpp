//参考，没有很理解到插入排序和归并排序的特点
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, temp, ed;
    int origin[105], next[105];
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &origin[i]);
    for(int i = 0; i < n; i++)
        scanf("%d", &next[i]);
    for(int i = 0; i < n - 1; i++){
        if(next[i + 1] < next[i]){
            temp = i + 1;
            break;
        }
    }
    for(ed = temp; ed < n; ed++){
        if(origin[ed] != next[ed])
            break;
    }
    if(ed == n){
        printf("Insertion Sort\n");
        sort(origin, origin + temp + 1);
    } else{
        printf("Merge Sort\n");
        int flag = 1, k = 1;
        while(flag){
            flag = 0;
            for(int i =  0; i < n; i++){
                if(origin[i] != next[i]){
                    flag = 1;
                }
            }
            k = k * 2;
            for(int i = 0; i < n / k; i++)
                sort(origin + i * k, origin + (i + 1) * k);
            sort(origin + n / k * k, origin + n);
        }
    }
    for(int i = 0; i < n; i++){
        printf("%d", origin[i]);
        if(i != n - 1) printf(" ");
    }
    return 0;
}
