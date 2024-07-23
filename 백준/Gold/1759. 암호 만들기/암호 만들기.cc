#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int l,c;
string a;
vector<string> passward;
vector<string> mo_list;
vector<string> ja_list;
bool visit[16] = { false };
//vector<char> mo;
int mo = 0;
void backtracking(int ct, int moum, int start, int jaum) {
    //현재 카운트가 입력받은 l과 같아 졌을때
    if (ct == l && moum < mo_list.size() && jaum>=2) {

        for (int i = 0; i < passward.size(); i++) {
            if (visit[i] == true) {
                cout << passward[i];
            }
        }
        cout << endl;
    }

    else {
        for (int i = start; i < passward.size(); i++) {

            //현재 비밀번호가 모음이고 모음을 
            if ((passward[i] == "a" || passward[i] == "e" || passward[i] == "i" || passward[i] == "o" || passward[i] == "u") && moum > 0) {
                visit[i] = true;
                backtracking(ct + 1, moum - 1, i+1, jaum);
                visit[i] = false;
            }

            else if ((passward[i] == "a" || passward[i] == "e" || passward[i] == "i" || passward[i] == "o" || passward[i] == "u") && moum == 0) {
                continue;
            }

            else {
                visit[i] = true;
                backtracking(ct + 1, moum, i+1, jaum + 1);
                visit[i] = false;
            }
        }
    }
    return;
}

int main() {

    cin >> l >> c;

    for (int i = 0; i < c; i++) {

        cin >> a;

        if (a == "a" || a == "e" || a == "i" || a == "o" || a == "u") {
            mo_list.push_back(a);
        }
        else {
            ja_list.push_back(a);
        }

        passward.push_back(a);

    }

    sort(passward.begin(), passward.end());

    backtracking(0, mo_list.size(), 0, 0);


    return 0;
}
