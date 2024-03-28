#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str, bomb, ret;

    cin >> str >> bomb;

    for (char c : str) {
        ret += c;
        if (ret.size() >= bomb.size() &&
            ret.substr(ret.size() - bomb.size(), bomb.size()) == bomb) {
            ret.erase(ret.end() - bomb.size(), ret.end());
        }
    }

    if (ret.size()) cout << ret << "\n";
    else cout << "FRULA\n";

    return 0;

}
