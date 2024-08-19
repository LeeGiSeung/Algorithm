#include <iostream>
using namespace std;

int main() 
{
    int N, T, P, s[6], cnt = 0;

    cin >> N;

    for (int i = 0; i < 6; i++)
        cin >> s[i];

    cin >> T >> P;

    for (int i = 0; i < 6; i++)
        cnt += (s[i] / T + (s[i] % T > 0));

    cout << cnt << '\n' << N / P << " " << N % P << '\n';

    return 0;
}