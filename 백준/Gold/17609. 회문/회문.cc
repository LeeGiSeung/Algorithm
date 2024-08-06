#include <iostream>
using namespace std;
int T, answer;
string str;
void checkPalindrome(int left, int right, bool isPseudo)
{
    int cnt = 0;
    while (left < right)
    {
        if (str[left] == str[right]) // 동일한 경우
        {
            ++left, --right;
        }
        else
        {
            if (isPseudo) // 이미 제거한 경우
            {
                if (answer == 3)
                {
                    answer = 2;
                }
                return;
            }
            checkPalindrome(left + 1, right, true);
            checkPalindrome(left, right - 1, true);
            return;
        }
    }
    answer = isPseudo;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> str;
        answer = 3;
        checkPalindrome(0, str.size() - 1, false);
        cout << answer << "\n";
    }
    return 0;
}