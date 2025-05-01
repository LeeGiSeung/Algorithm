#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//k = 상자에 담고자 하는 귤의 개수
//tangerine = 내가 가지고있는 귤의 개수

int solution(int k, vector<int> tangerine) {
    int answer = 0;

    vector<int> lst(10000001,0);

    for (int i = 0; i < tangerine.size(); i++) {
        lst[tangerine[i]]++;
        if (lst[tangerine[i]] == k) {
            return 1; //하나로 만약되면 더 볼 것도 없음
        }
    }

    sort(lst.begin(), lst.end());

    reverse(lst.begin(), lst.end());

    for (int i = 0; i < lst.size(); i++) {
        answer++;
        k -= lst[i];
        if (k <= 0) break;
    }
    //종류가 적어야 되니

    return answer;
}