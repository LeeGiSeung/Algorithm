#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int check[101];

int find_island(int island) {
    if (check[island] == island) return island;
    return check[island] = find_island(check[island]);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    sort(costs.begin(), costs.end(), [](const auto& a, const auto& b) {
        return a[2] < b[2];
        });

    for (int i = 0; i < n; i++) {
        check[i] = i;
    }

    for (int i = 0; i < costs.size(); i++) {
        int start = find_island(costs[i][0]);
        int end = find_island(costs[i][1]);
        int cost = costs[i][2];

        if (start != end) { //연결이 안돼있으면
            check[end] = start;
            answer += cost;
        }
    }

    return answer;
}

int main() {

    vector<vector<int>> v({{0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 1}, {2, 3, 8}} );

    solution(4, v);

    return 0;
}