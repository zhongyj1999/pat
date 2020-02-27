#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int a, b, sumab;
    int flag = 0;
    int ab[3]={0};
    cin >> a >> b;
    sumab = a + b;
    //cout << sumab << endl;
    //cout << abs(sumab) << endl;
    if(sumab == 0){
        //cout << 1 << endl;
        cout << sumab << endl;
    }
    if(abs(sumab) < 1000 && sumab != 0){
        cout << sumab << endl;
    }
    if(abs(sumab) >= 1000){
        if(sumab < 0)
            cout << '-';
        sumab = abs(sumab);
        //cout << sumab << endl;
        while(sumab > 0){
            ab[flag] = sumab%1000;
            //cout << ab[flag] << endl;
            sumab = sumab/1000;
            if((sumab/1000) < 1){
                flag++;
                ab[flag] = sumab;
                break;
            }
            flag++;
        }
        cout << flag <<endl;
        cout.fill('0');
        for(int i = flag; i > 0; i--){
            if(i == flag){
                cout << ab[i] << ',';
            }
            if(i < flag){
                cout.width(3);
                cout << ab[i] << ',';
            }
        }
        cout.width(3);
        cout << ab[0] << endl;
    }
    return 0;
}
