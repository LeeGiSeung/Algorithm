#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    stack<char> sc;
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            cout << s[i];
        }
        else {
            if (s[i] == '(') {
                sc.push(s[i]);
            }

            else if (s[i] == '+' || s[i] == '-') {
                while (!sc.empty() && sc.top() != '(') {
                    cout << sc.top();
                    sc.pop();
                }
                sc.push(s[i]);
            }
            else if (s[i] == '*' || s[i] == '/') {
                while (!sc.empty() && (sc.top() == '*' || sc.top() == '/')) {
                    cout << sc.top();
                    sc.pop();
                }
                sc.push(s[i]);
            }
            else if (s[i] == ')') {
                while (!sc.empty() && sc.top() != '(') {
                    cout << sc.top();
                    sc.pop();
                }
                sc.pop();
            }
        }
    }

    while (!sc.empty()) {
        cout << sc.top();
        sc.pop();
    }

    return 0;
}