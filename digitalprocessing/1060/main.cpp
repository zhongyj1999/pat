#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, posa = 0, posb = 0, sa, sb;
    scanf("%d", &n);
    string a, b, ansa, ansb;
    ansa.resize(n, '0');
    ansb.resize(n, '0');
    cin >> a >> b;
    sa = a.length();
    sb = b.length();
    posa = a.find('.');
    if(posa == -1) posa = a.length();
    posb = b.find('.');
    if(posb == -1) posb = b.length();
    bool flag = false;
    int cnt = 0;
    for(int i = 0; i < a.length(); i++){
        if(a[i] >= '1' && a[i] <= '9' && flag == false){
            sa = i;
            flag = true;
        }
        if(flag){
            if(a[i] != '.') ansa[cnt++] = a[i];
        }
    }
    flag = false;
    cnt = 0;
    for(int i = 0; i < b.length(); i++){
        if(b[i] >= '1' && b[i] <= '9' && flag == false){
            sb = i;
            flag = true;
        }
        if(flag){
            if(b[i] != '.') ansb[cnt++] = b[i];
        }
    }
    //cout << ansa << ' ' << ansb<<endl;
    //cout << posa << ' ' << sa<<endl;
    //cout << posb << ' ' << sb<<endl;
    if(ansa[0] == '0' && ansb[0] == '0'){
        cout << "YES 0." << ansa << "*10^0";
    }
    else if(ansa == ansb && posa - sa == posb - sb){
        cout << "YES 0." << ansa << "*10^";
        if(posa < sa) cout << posa - sa + 1;
        else cout << posa - sa;
    }else{
        cout << "NO 0.";
        if(ansa[0] == '0') cout << ansa <<"*10^0 0.";
        else{
            cout << ansa << "*10^";
            if(posa < sa - 1) cout << posa - sa + 1 << " 0.";
            else if(posa == sa - 1) cout << posa - sa + 2 << " 0.";
            else cout << posa - sa << " 0.";
        }
        if(ansb[0] == '0') cout << ansb <<"*10^0";
        else{
            cout << ansb << "*10^";
            if(posb < sb - 1) cout << posb - sb + 1;
            else if(posb == sb - 1) cout << posb - sb + 2;
            else cout << posb - sb;
        }
    }
    return 0;
}
