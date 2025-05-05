#include <string>
#include <vector>

using namespace std;

vector<int> root;

int union_find(int x) {
    if (root[x] == x) return x; //자기 자신이 최상위면 그냥 리턴
    else return root[x] = union_find(root[x]);
    
}

void union_link(int x, int y) {
    int _x = union_find(x);
    int _y = union_find(y);

    if (_x < _y) { //일단 숫자가 작은것들을 최상위 노드로
        root[_y] = _x;
    }
    else {
        root[_x] = _y;
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = n; //최대 갯수는 n임

    for (int i = 0; i < n; i++)
    {
        root.push_back(i);
    }

    for (int i = 0; i < n; i++) { // i = 네트워크 자신
        for (int j = 0; j < computers[i].size(); j++) { // i가 연결될 네트워크
            if (i == j) continue; //자기자신은 할 필요없음
            if (computers[i][j] == 0) continue;

            if (union_find(i) != union_find(j)) { //최상위 루트가 다를 겨우 이어준다.
                union_link(i, j);
                answer--; //이어줬으니 정답 -1
            }
            //최상위 루트가 같다? -> 이미 연결된 것임
        }
    }


    return answer;
}

int main() {
    //4, [[1, 0, 0, 1], [0, 1, 1, 0], [0, 1, 1, 1], [1, 0, 1, 1]]
    vector<vector<int>> v({ {1, 0, 0, 1},{0, 1, 1, 0},{0, 0, 1, 1}, {1, 0, 1 ,1} });

    solution(4, v);

}