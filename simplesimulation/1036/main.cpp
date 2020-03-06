#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
struct stu{
    char name[12], id[12];
    char gender[2];
    int grade;
};

bool cmp1(stu a, stu b){
    if(strcmp(a.gender, b.gender) != 0)
        return strcmp(a.gender, b.gender) > 0;
    else
        return a.grade < b.grade;
}

int main()
{
    int n, exsit[2] = {0};
    scanf("%d", &n);
    vector<stu> s(n);
    for(int i = 0; i < n; i++){
        scanf("%s %s %s %d", &s[i].name, &s[i].gender, &s[i].id, &s[i].grade);
        if(strcmp(s[i].gender, "M") == 0) exsit[0] = 1;
        if(strcmp(s[i].gender, "F") == 0) exsit[1] = 1;
    }
    sort(s.begin(), s.end(), cmp1);
    if(exsit[0] == 1 && exsit[1] == 1){
        printf("%s %s\n", s[s.size() - 1].name, s[s.size() - 1].id);
        printf("%s %s\n", s[0].name, s[0].id);
        printf("%d\n", s[s.size() - 1].grade - s[0].grade);
    }else if(exsit[0] == 1){
        printf("Absent\n%s %s\nNA\n", s[0].name, s[0].id);
    }else if(exsit[1] == 1){
        printf("%s %s\nAbsent\nNA\n", s[s.size() - 1].name, s[s.size() - 1].id);
    }else{
        printf("Absent\nAbsent\nNA\n");
    }
    return 0;
}
