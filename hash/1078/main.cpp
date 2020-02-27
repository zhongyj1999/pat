#include <iostream>
#include <vector>

using namespace std;
int size, n, hasht[10100];

bool isprim(int a){
    if(a == 1) return false;
    for(int i = 2; i * i <= a; i++)
        if(a % i == 0) return false;
    return true;
}

void insert(int key){
    for(int i = 0; i < size; i++){
        int index = (key + i * i) % size;
        if(hasht[index] == 0){
            hasht[index] = 1;
            printf("%d", index);
            return ;
        }
    }
    printf("-");
}

int main()
{
    int m, n;
    scanf("%d %d", &size, &n);
    while(!isprim(size)) size++;
    for(int i = 0; i < n; i++){
        int temp;
        scanf("%d", &temp);
        if(i != 0) printf(" ");
        insert(temp);
    }
    return 0;
}
