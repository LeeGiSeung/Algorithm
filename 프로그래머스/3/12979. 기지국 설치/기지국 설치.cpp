#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    sort(stations.begin(), stations.end());

    int index = 1;
    int stations_index = 0;

    while (index <= n) {
        if (index >= stations[stations_index] - w && index <= stations[stations_index] + w) {
            //범위안에 있으면 그냥 지나감
            index = stations[stations_index] + w + 1;
            stations_index++;
        }
        else {
            index += w * 2 + 1;
            answer++;
        }
    }

    return answer;
}

int main() {
    vector<int> v({ 9 });

    solution(16, v, 2);
}

