#include <string>
#include <vector>
#include <queue>

using namespace std;
vector<int> node[100001];
int result[100001];
bool check[100001];


vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;

    for (int i = 0; i < roads.size(); i++) {
        int a = roads[i][0];
        int b = roads[i][1];

        node[a].push_back(b);
        node[b].push_back(a);

    }

    queue<pair<int, int>> q;
    q.push({ destination,0 });

    while (!q.empty()) {
        int cur = q.front().first;
        int count = q.front().second;
        q.pop();

        for (int i = 0; i < node[cur].size(); i++) {
            int next = node[cur][i];
            if (check[next] == false) {
                check[next] = true;
                result[next] = count + 1;
                q.push({ next, count + 1 });
            }    
        }
    }

    for (int i = 0; i <  sources.size(); i++) {
        int x = result[sources[i]];
        if (sources[i] == destination) {
            answer.push_back(0);
        }
        else if (x == 0) {
            answer.push_back(-1);
        }
        else {
            answer.push_back(result[sources[i]]);
        }

    }

    return answer;
}

int main() {

    vector<vector<int>> v({ {1,2},{2,3} });
    vector<int> v2({ 2,3 });

    solution(3,v,v2,1);

    return 0;
}