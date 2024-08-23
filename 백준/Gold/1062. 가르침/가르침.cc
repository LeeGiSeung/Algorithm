#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, K;
bool alpha[26];
int ans;
vector<string> v;

void dfs(int idx, int remain){
    if(!remain){
        int cnt = 0;
        for(string elem : v){
            bool flag = true;
            for(char ch : elem){
                if(!alpha[ch - 'a']){
                    flag = false;
                    break;
                }
            }
            if(flag) cnt++;
        }
        ans = max(ans, cnt);
        if(ans == N){
            cout << N << '\n';
            exit(0);
        }
        return;
    }
    for(int i = idx; i < 26; i++){
        if(alpha[i]) continue;
        alpha[i] = true;
        dfs(i, remain - 1);
        alpha[i] = false;
    }
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    string str = "";
    for(int i = 0; i < N; i++){
        cin >> str;
        v.push_back(str.substr(4, str.length() - 8));
    }
    if(K < 5){
        cout << 0 << '\n';
        return 0;
    }
    // a c i n t 필수
    alpha[0] = true; alpha[2] = true; alpha[8] = true;
    alpha[13] = true; alpha[19] = true;    

    dfs(0, K-5);
    cout << ans << '\n';
    return 0;
}