#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
    int cnt = 1;
    string D[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    for(int i = 0; i < 2; i++){
        string a, b;
        cin >> a >> b;
        //cout << a.length() << b.length() <<endl;
        int l = min(a.length(), b.length());
        for(int j = 0; j < l; j++){
            if(a[j] == b[j]){
                if(cnt == 1){
                    if(a[j] >= 'A' && a[j] <= 'G'){
                        cout << D[a[j] - 'A'] << " ";
                        cnt++;
                    }
                }else if(cnt == 2){
                    if(a[j] >= 'A' && a[j] <= 'N'){
                        cout << a[j] - 'A' + 10 << ":";
                        cnt++;
                        break;
                    }else if(a[j] >= '0' && a[j] <= '9'){
                        cout << "0" << a[j] << ":";
                        cnt++;
                        break;
                    }
                }else{
                    if((a[j] >= 'a' && a[j] <= 'z') || (a[j] >= 'A' && a[j] <= 'Z')){
                        printf("%02d", j);
                        return 0;
                    }
                }
            }
        }
    }
    //return 0;
}
