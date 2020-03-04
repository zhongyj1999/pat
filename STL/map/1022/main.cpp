#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;
map<string, vector<string>> book, author, key, pub, year;

int main()
{
    int n, m;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        string id, y;
        int num = 4;
        cin >> id;
        getchar();
        while(num-- > 0){
            string s;
            getline(cin , s);
            if(num == 1){
                int j, temp = 0;
                for(j = 0; j < s.length(); j++){
                    if(s[j] == ' '){
                        string t = s.substr(temp, j - temp);
                        temp = j + 1;
                        //cout << t << endl;
                        key[t].push_back(id);
                    }
                }
                string t = s.substr(temp);
                //cout << t << endl;
                key[t].push_back(id);
            }
            else{
                //cout << s << endl;
                if(num == 3) book[s].push_back(id);
                else if(num == 2) author[s].push_back(id);
                else pub[s].push_back(id);
            }
        }
        cin >> y;
        year[y].push_back(id);
        //printf("%d\n", y, i);
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        int temp;
        scanf("%d:", &temp);
        printf("%d: ", temp);
        getchar();
        string s;
        getline(cin ,s);
        cout << s << endl;
        if(temp == 1){
            if(book[s].size() == 0) printf("Not Found\n");
            else{
                sort(book[s].begin(), book[s].end());
                for(int j = 0; j < book[s].size(); j++)
                    cout << book[s][j] << endl;
            }
        }else if(temp == 2){
            if(author[s].size() == 0) printf("Not Found\n");
            else{
                sort(author[s].begin(), author[s].end());
                for(int j = 0; j < author[s].size(); j++)
                    cout << author[s][j] <<endl;
            }
        }else if(temp == 3){
            if(key[s].size() == 0) printf("Not Found\n");
            else{
                sort(key[s].begin(), key[s].end());
                for(int j = 0; j < key[s].size(); j++)
                    cout << key[s][j] <<endl;
            }
        }else if(temp == 4){
            if(pub[s].size() == 0) printf("Not Found\n");
            else{
                sort(pub[s].begin(), pub[s].end());
                for(int j = 0; j < pub[s].size(); j++)
                    cout << pub[s][j] <<endl;
            }
        }else if(temp == 5){
            if(year[s].size() == 0) printf("Not Found\n");
            else{
                sort(year[s].begin(), year[s].end());
                for(int j = 0; j < year[s].size(); j++)
                    cout << year[s][j] <<endl;
            }
        }
    }
    return 0;
}
