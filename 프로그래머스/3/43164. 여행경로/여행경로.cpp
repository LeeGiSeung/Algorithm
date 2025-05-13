#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;
vector<vector<string>> v;
vector<string> answer;
bool check[10002];
bool ismatch = false;

void dfs(string start, int count) {
    answer.push_back(start);



    if (count == v.size()) {
        ismatch = true;
    }

    for (int i = 0; i < v.size(); i++) {
        if (check[i]) continue;
        if (v[i][0] == start) {
            check[i] = true;
            dfs(v[i][1], count + 1);
            
            if (!ismatch) {
                check[i] = false;
                answer.pop_back();
            }

        }
    }


}

vector<string> solution(vector<vector<string>> tickets) {


    sort(tickets.begin(), tickets.end(), [](const auto &a, const auto&b) {
        return a[1] < b[1];
        });

    v = tickets;

    dfs("ICN", 0);

    return answer;
}

int main() {

    vector<vector<string>> v({{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"}} );
    //vector<vector<string>> v({ {"ICN", "ABC"}, {"ICN", "BBB"}, {"JFK", "HND"} });

    solution(v);

    return 0;
}