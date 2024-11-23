#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, l;
int result;
int REMAINING_COUNT = 0;
int PLANK_POSITION = 0;
int flankcount;

vector<pair<int, int>> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //n 널빤지 갯수
    //l 널빤지 길이
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({ a,b });
    }

    sort(v.begin(), v.end());
    //1 6
    //8 12
    //13 17

    //처음 이면 무조건 깔아야하니까 생각하면안됨
    for (int i = 0; i < v.size(); i++) {
        int a = v[i].first;
        int b = v[i].second;
        //이전 판자 에서 바로 처리가능하고 끝나는 경우의 수
        if (PLANK_POSITION >= b) {
            continue;
        }
        //이전 판자를 일부만 사용하는 경우의 수
        else if (PLANK_POSITION >= a) {
            a = PLANK_POSITION;
            flankcount = (b - a) / l;
            if ((b - a) % l != 0) {
                flankcount++;
                PLANK_POSITION = a + flankcount * l;
            }
            else {
                PLANK_POSITION = b;
            }
            result += flankcount;
        }
        //새롭게 시작하는 경우의 수
        else {
            flankcount = (b - a) / l;
            if ((b - a) % l != 0) {
                flankcount++;
                PLANK_POSITION = a + flankcount * l;
            }
            else {
                PLANK_POSITION = b;
            }
            result += flankcount;
        }
    }

    cout << result;

    return 0;

}

