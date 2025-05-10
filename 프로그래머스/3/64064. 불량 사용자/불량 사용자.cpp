#include <string>
#include <vector>
#include <set>

using namespace std;

bool check[9];
set<string> s;
vector<string> userid;
vector<string> bannedid;

bool check_ban(string user, string ban) {
    if (user.size() != ban.size()) return false;

    for (int i = 0; i < user.size(); i++) {
        if (ban[i] == '*') continue;
        if (user[i] != ban[i]) return false;
    }
    return true;
}

void dfs(int idx) {
    if (idx == bannedid.size()) {
        string str = "";

        for (int i = 0; i < userid.size(); i++) {
            if (check[i] == true) {
                str += i + '0';
            }
        }

        s.insert(str);
        return;
    }

    for (int i = 0; i < userid.size(); i++) {
        if (check[i]) continue;
        if (check_ban(userid[i], bannedid[idx])) {
            check[i] = true;
            dfs(idx + 1);
            check[i] = false;
        }

    }

}

int solve(int index) {
    int count = 0;

    dfs(0);

    count = s.size();

    return count;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;

    userid = user_id;
    bannedid = banned_id;

    answer = solve(0);

    return answer;
}

int main() {

    return 0;
}