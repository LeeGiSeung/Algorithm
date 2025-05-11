#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int limit;
bool solve(int _count, vector<int> _stones) {

    int minus = 0;

    for (int i = 0; i < _stones.size(); i++) {
        if (_stones[i] - _count <= 0) {
            minus++; 
        }
        else { //연속으로 건널 수 있으면 minus는 초기화
            minus = 0;
        }

        if (limit == minus) return false;

    }

    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    limit = k;

    int start = 0;
    int end = *max_element(stones.begin(), stones.end()); //주소반환
    int mid = 0;
    //건널 수 있는 최대 돌다리는 end개가 최대임

    while (start <= end) {
        mid = (end + start) / 2; //이분탐색으로 중간값부터 검사

        if (solve(mid, stones)) {
            //가능하다는건 하나 더 늘려서 시험해봐도됨
            start = mid + 1;
        }
        else {
            //안된다는건 줄여봐야함
            end = mid - 1;
        }
    }
    
    answer = start;

    return answer;
}

int main() {

    vector<int> v({ 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 });

    solution(v, 3);

    return 0;
}