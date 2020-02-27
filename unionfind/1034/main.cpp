#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> fa;
string Name[27] = {"AAA", "BBB", "CCC", "DDD", "EEE",
                   "FFF", "GGG", "HHH", "III", "JJJ",
                   "KKK", "LLL", "MMM", "NNN", "OOO",
                   "PPP", "QQQ", "RRR", "SSS", "TTT",
                   "UUU", "VVV", "WWW", "XXX", "YYY",
                   "ZZZ"};
int Time[27] = {0};
int Course[27] = {0};

int findFather(int x){
    int a = x;
    while(x != fa[x])
        x = fa[x];
    while(a != fa[a]){
        int z = a;
        a = fa[a];
        fa[z] = x;
    }
    return x;
}

void Union(int a, int b){
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB) fa[faA] = faB;
}

void init(int x){
    for(int i =1; i <= x; i++)
        fa[i] = i;
}

int main()
{
    int n, k, t, gangs = 0;
    int head1 = 0;
    string a, b, head, head2;
    vector<int> root, cnt;
    a.resize(3);
    head2.resize(3);
    b.resize(3);
    scanf("%d %d", &n, &k);
    fa.resize(n + 1);
    root.resize(n + 1);
    cnt.resize(n + 1);
    head.resize(3 * n + 1);
    cnt = {0};
    root = {0};
    init(n);
    for(int i = 1; i <= n; i++){
        scanf("%s", &a[0]);
        scanf("%s", &b[0]);
        scanf("%d", &t);
        //printf("%s %s", a.c_str(), b.c_str());
        int posa = 0, posb = 0;
        for(int j = 0; j < 27; j++){
            if(Name[j].find(a) == 0)
                posa = j + 1;
            if(Name[j].find(b) == 0){
                posb = j + 1;
            if(posa && posb)
                break;
            }
        }
        //printf("%d %d\n", posa, posb);
        if(Course[posa] == 0)
            Course[posa] = i;
        if(Course[posb] == 0)
            Course[posb] = i;
        Union(findFather(Course[posa]), findFather(Course[posb]));
        Time[posa] += t;
        Time[posb] += t;
        root[findFather(i)] += t;
    }
    for(int i = 1; i <= 27; i++){
        if(Course[i] != 0)
            cnt[findFather(Course[i])]++;
    }
    for(int i = 1; i <= n; i++){
        if((root[i] > t) && (cnt[i] > 2)){
            gangs++;
            int z = 0;
            for(int j = 1; j <= n; j++){
                if(Course[j] == i){
                    head.insert(head1, Name[Time[z]>Time[j]?z:j]);
                    z = Time[z]>Time[j]?z:j;
                    head1 += 3;
                }
            }
        }
    }
    if(gangs == 0)
        printf("0");
    else{
        printf("%d\n", gangs);
        int pos;
        int head3 = 0;
        for(int i = 0; i < gangs; i++){
            for(int j = 0; j < 27; j++){
                head2.assign(head, head3, 3);
                head3 += 3;
                if(Name[j].find(head2) == 0)
                    pos = j + 1;
                printf("%s %d\n", head2.c_str(), cnt[pos]);
            }
        }
    }
    return 0;
}
