#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> node[20002];
int max_count;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    // 1번 노드에서 가장 멀리 떨어진 노드의 갯수

    for (int i = 0; i < edge.size(); i++) {
        node[edge[i][0]].push_back(edge[i][1]);
        node[edge[i][1]].push_back(edge[i][0]);
    }

    queue<int> q;
    vector<int> check(n + 1, -1);
    check[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int index = q.front();
        q.pop();

        for (int i = 0; i < node[index].size(); i++) {
            if (check[node[index][i]] == -1) { //아직 방문 안했을때
                check[node[index][i]] = check[index] + 1;
                q.push(node[index][i]);
            }
        }
    }

    int max_count = *max_element(check.begin(), check.end());

    for (int i = 1; i <= n; i++) {
        if (max_count == check[i]) answer++;
    }

    return answer;
}

int main() {
    vector<vector<int>> v1({{ 3, 6 }, { 4, 3 }, { 3, 2 }, { 1, 3 }, { 1, 2 }, { 2, 4 }, { 5, 2 }});

    solution(6, v1);

    return 0;
}