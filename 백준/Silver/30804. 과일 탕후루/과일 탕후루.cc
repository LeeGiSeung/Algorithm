#include <iostream>
#include <queue>
using namespace std;
int N, types, cnt[10], answer;
queue<int> q;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    while (N--)
    {
        int fruit;
        cin >> fruit;

        q.push(fruit);

        if (cnt[fruit]++ == 0)
        {
            ++types;
        }

        while (types > 2)
        {
            fruit = q.front();
            q.pop();

            if (--cnt[fruit] == 0)
            {
                --types;
            }
        }

        answer = max(answer, static_cast<int>(q.size()));
    }

    cout << answer;
    return 0;
}