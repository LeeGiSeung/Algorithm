#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;

    long long max_time = *max_element(times.begin(), times.end());

    long long end = max_time * n;
    long long start = 1;
    long long mid;

    while (start <= end) {

        long long count = 0;
        mid = (end + start) / 2;

        for (int i = 0; i < times.size(); i++) {
            count += mid / (long long)times[i];
        }

        if (count < n) { //작으면 시간 늘려야함
            start = mid + 1;
        }
        else if (count >= n) { //크면 시간(end) 줄여야함 같아도 최적의 시간을 찾기 위해 줄여야함
            answer = mid;
            end = mid - 1;
        }

    }

    return answer;
}