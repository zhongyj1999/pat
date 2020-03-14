#include <iostream>
#include <cmath>
#include <stack>

using namespace std;
const int maxn = 1e5 + 10;
const int bn = sqrt(maxn);
const int bl = ceil(maxn/bn);
int table[maxn] = {0};
int block[bl] = {0};
stack<int> st;

void Push(int v){
    st.push(v);
    ++block[v / bn];
    ++table[v];
}

void Pop(){
    int temp = st.top();
    st.pop();
    --block[temp / bn];
    --table[temp];
    printf("%d\n", temp);
}

void PeekMedian(){
    int k = st.size()%2 == 1 ? (st.size()+1)/2 : st.size() / 2;
    int sum=0, index;
    for(index=0;index<bl && sum+block[index]<k;index++)
        sum+=block[index];
    for(int i=index*bn;i<(index+1)*bn;i++){
        sum+=table[i];
        if(sum>=k){
            printf("%d\n",i);
            return;
        }
    }
}

int main()
{
    int n, num;
    char t[20];
    scanf("%d", &n);
    //printf("%d %d %d\n", bn, bl, maxn/bn);
    for(int i = 0; i < n; i++){
        scanf("%s", t);
        if(t[1] == 'u'){
            scanf("%d", &num);
            Push(num);
        }else if(t[1] == 'o'){
            if(st.empty() == false){
                Pop();
            }else{
                printf("Invalid\n");
            }
        }else{
            if(st.empty() == false){
                PeekMedian();
            }else{
                printf("Invalid\n");
            }
        }

    }
    return 0;
}
