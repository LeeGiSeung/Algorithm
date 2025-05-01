#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//한 번에 최대 2명씩 밖에 탈 수 없고
// [70kg, 50kg, 80kg, 50kg] 무게 제한이 100kg
//구명보트를 최대한 적게 사용하여 모든 사람을 구출
int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.begin(), people.end());
    int curkg = 0;

    if (people.size() == 1) {
        return 1;
    }

    //0 1 2 3 4
    //12 34
    //작은놈이랑 큰놈이랑 비교해야함

    //다 탈출 가능하다했음
    int left = 0;
    int right = people.size() - 1;
    while (left <= right) {
        if (people[left] + people[right] <= limit) {
            answer += 1; // 보트 1개로됨
            left += 1;
            right -= 1;
        }
        else { //보트 2개로 안되면 그냥 제일 무거운 놈은 보트 1개로 바로 보내야함
            right -= 1;
            answer += 1;
        }
    }

    return answer;
}


int main() {
    vector<int> v = { 139, 138, 1, 2 };
    solution(v, 140);

    return 0;
}
