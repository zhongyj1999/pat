#include <iostream>
#include <string>
#include <vector>

using namespace std;

string c[6] = {"*", "Shi", "Bai", "Qian", "Yi", "Wan"};
string num[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
int J[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
vector<string> res;

int main()
{
    int n;
    scanf("%d", &n);
    if(n == 0){
        cout << "ling";
        return 0;
    }
    if(n < 0){
        cout << "Fu ";
        n = -n;
    }
    int part[3];
    part[0] = n / 100000000;
    part[1] = (n % 100000000) / 10000;
    part[2] = n % 10000;
    bool zero = false;
    int printCnt = 0;
    for(int i = 0; i < 3; i++){
        int temp = part[i];
        for(int j = 3; j >= 0; j--){
            int curPos = 8 - i * 4 + j;
            if(curPos >= 9) continue;
            int cur = (temp / J[j]) % 10;
            if(cur != 0){
                if(zero){
                    printCnt++ == 0 ? cout << "ling" : cout << " ling";
                    zero = false;
                }
                if(j == 0)
                    printCnt++ == 0 ? cout << num[cur] : cout << ' ' << num[cur];
                else
                    printCnt++ == 0 ? cout << num[cur] << ' ' << c[j] : cout << ' ' << num[cur] << ' ' << c[j];
            }else{
                if(!zero && j != 0 && n / J[curPos] >= 10) zero = true;
            }
        }
        if(i != 2 && part[i] > 0) cout << ' ' << c[i + 4];
    }
    return 0;
}
/*
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;
bool m[4] = {false};

string s1[] = {"Wan", "Yi"};
string s2[] = {"Shi", "Bai", "Qian"};
string s3[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

void output(int num, int cnt){
    int n = 0, temp = num, flag = 0;
    int ans[4];
    while(temp > 0){
        ans[n] = temp % 10;
        temp /= 10;
        n++;
    }
    if(n == 4){
        while(n-- > 0){
            if(ans[n] > 0){
                if(flag == 1){
                    cout << s3[0] << " ";
                    flag = 0;
                }
                if(n != 0){
                    cout << s3[ans[n]] << " " << s2[n - 1];
                    printf(" ");
                }else{
                    cout << s3[ans[n]];
                }
            }else if(ans[n] == 0){
                flag = 1;
            }
        }
    }else{
        if(m[cnt] != true){
            cout << s3[0] << " ";
        }
        while(n-- > 0){
            if(ans[n] > 0){
                if(flag == 1){
                    cout << s3[0] << " ";
                    flag = 0;
                }
                if(n != 0){
                    cout << s3[ans[n]] << " " << s2[n - 1];
                    printf(" ");
                }else{
                    cout << s3[ans[n]];
                }
            }else if(ans[n] == 0){
                flag = 1;
            }
        }
    }
}

int main()
{
    string s;
    cin >> s;
    int num = stoi(s);

    if(num < 0){
        printf("Fu ");
        num = abs(num);
        s.erase(0, 1);
    }
    if(num == 0){
        cout << s3[0];
        return 0;
    }
    int l = s.length();
    int cnt = l / 4;
    m[cnt] = true;
    for(; cnt >= 0; cnt--){
        if(cnt == 2){
            cout << s3[stoi(s.substr(0, 1))] << " " << s1[cnt - 1];
            s.erase(0, 1);
            if(stoi(s) == 0) return 0;
            else printf(" ");
        }else if(cnt == 1){
            l = s.length();
            string t = s.substr(0, l - cnt * 4);
            int temp = stoi(t);
            if(temp == 0){
                if(stoi(s.substr(l - cnt * 4)) >= 1000)
                    cout << s3[0] << " ";
                continue;
            }
            output(temp, cnt);
            if(m[cnt] != true) printf(" ");
            cout << s1[cnt - 1];
            s.erase(0, l - cnt * 4);
            if(stoi(s) == 0) return 0;
            else printf(" ");
        }else if(cnt == 0){
            string t = s.substr(0);
            int temp = stoi(t);
            if(temp == 0) break;
            output(temp, cnt);
        }
    }
    return 0;
}
*/
