#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> camera;

int solution(vector<vector<int>> routes) {
    int answer = 1;
 
    sort(routes.begin(), routes.end());

    int camera_pos = routes[0][1]; //카메라는 우측 좌표만 생각하고있으면 됨 우측 좌표보다 크면 새로운 감시카메라인거

    for (int i = 1; i < routes.size(); i++) {
        if (routes[i][0] > camera_pos) {
            answer++;
            camera_pos = routes[i][1];
        }
        else if (routes[i][1] < camera_pos) {
            camera_pos = routes[i][1];
        }
    }

    return answer;
}

int main() {
    vector<vector<int>> v({ {-20,-15 }, { -14,-5 }, { -18,-13 }, { -5,-3 }});

    solution(v);
}

