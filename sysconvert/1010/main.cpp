#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>

using namespace std;

long long convert(string n, long long radix){
    long long sum = 0;
    int index = 0, temp = 0;
    for(auto it = n.rbegin(); it != n.rend(); it++){
        temp = isdigit(*it) ? *it - '0' : *it - 'a' + 10;
        sum += temp * pow(radix, index++);
    }
    return sum;
}

long long find_radix(string n, long long num){
    char it = *max_element(n.begin(), n.end());
    long long low = (isdigit(it) ? it - '0' : it - 'a' + 10) + 1;
    long long high = max(num, low);
    while(low <= high){
        long long mid = (low + high) / 2;
        long long t = convert(n, mid);
        if(t < 0 || t > num) high = mid - 1;
        else if(t == num) return mid;
        else low = mid + 1;
    }
    return -1;
}

int main(){
    string n1, n2;
    long long tag = 0, radix = 0, result_radix;
    cin >> n1 >> n2 >> tag >> radix;
    result_radix = tag == 1 ? find_radix(n2, convert(n1, radix)) : find_radix(n1, convert(n2, radix));
    if(result_radix != -1){
        printf("%lld", result_radix);
    }else{
        printf("Impossible");
    }
    return 0;
}

/*
#include <iostream>
#include <cmath>

using namespace std;

int convert(string s, string t, int rad){
    int ans = 0, radix = -1;
    for(int i = 0; i < s.length(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            ans = ans + (s[i] - '0') * pow(rad, s.length() - 1 - i);
        }else{
            ans = ans + (s[i] - 'a' + 10) * pow(rad, s.length() - 1 - i);
        }
    }
    //printf("%d\n", ans);
    for(int i = 0; i < t.length(); i++){
        if(t[i] >= '0' && t[i] <= '9'){
            radix = max(t[i] - '0' + 1, radix);
        }else{
            radix = max(t[i] - 'a' + 11, radix);
        }
    }
    if(radix == 1) return 0;
    while(1){
        int tempans = 0;
        for(int i = 0; i < t.length(); i++){
            if(t[i] >= '0' && t[i] <= '9'){
                tempans = tempans + (t[i] - '0') * pow(radix, t.length() - 1 - i);
            }else{
                tempans = tempans + (t[i] - 'a' + 10) * pow(radix, t.length() - 1 - i);
            }
        }
        //printf("%d\n", tempans);
        if(tempans == ans) return radix;
        else if(tempans > ans) return 0;
        radix++;
    }
}

int main()
{
    string a, b;
    int tag, radix, r = 0;
    cin >> a >> b >> tag >> radix;
    if(a == b){
        printf("%d", radix);
        return 0;
    }
    if(tag ==  1){
        r = convert(a, b, radix);
    }else{
        r = convert(b, a, radix);
    }
    if(r != 0) printf("%d", r);
    else printf("Impossible");
    return 0;
}
*/
