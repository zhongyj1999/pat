#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int first = 0, len = 0, maxn = sqrt(n);
    for(int i = 2; i <= maxn; i++){
        int temp = 1, j;
        for(j = i; j <= maxn; j++){
            temp *= j;
            if(n % temp != 0) break;
        }
        if(j - i > len){
            first = i;
            len = j - i;
        }
    }
    if(first == 0) printf("1\n%d", n);
    else{
        printf("%d\n", len);
        for(int i = first; i < first + len; i++){
            printf("%d", i);
            if(i != first + len - 1) printf("*");
        }
    }
    return 0;
}


/*
#include <iostream>
#include <vector>

using namespace std;
vector<int> seq, temp;
int maxl = -1;

bool isprim(int a){
    if(a == 1) return false;
    for(int i = 2; i * i <= a; i++)
        if(a % i == 0) return false;
    return true;
}

int main()
{
    int n;
    scanf("%d", &n);
    if(isprim(n)){
        printf("1\n%d", n);
        return 0;
    }else if(n % 2 == 1){
        for(int i = 3; i <= n / 3; i++){
            if(n % i == 0){
                printf("1\n%d", i);
                return 0;
            }
        }
    }else{
        int a = n;
        for(int i = 2; i * i < n; i++){
            for(int j = i; j < n / 2; j++){
                if(a % j == 0){
                    a /= j;
                    if(temp.size() == 0)
                        temp.push_back(j);
                    else if(j == (temp.back() + 1)){
                        temp.push_back(j);
                        int b = temp.size();
                        if(b > maxl){
                            seq = temp;
                            maxl = temp.size();
                        }
                    }
                    if(a <= j) break;
                }else{
                    temp.clear();
                    a = n;
                    break;
                }
            }
        }
        printf("%d\n", seq.size());
        for(int i = 0; i < seq.size(); i++){
            printf("%d", seq[i]);
            if(i != seq.size() - 1) printf("*");
        }
    }
    return 0;
}
*/
