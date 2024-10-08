#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int n, m;
int map[60][60];

int result = 1;


void solve(int cur, int x, int y) {
	//꼭짓점은 4개여야함

	//one은 i값은 min j값은 min
	//two는 i값은 min j값은 max
	//three i값은 max j값은 min
	//four  i값은 max j값은 max
	//42101 
	//22100
	//22101

	vector<int> x_list;
	vector<int> y_list;

	for (int i = x; i < n; i++) {
		if (map[i][y] == cur) x_list.push_back(i);
	}

	for (int j = y; j < m; j++) {
		if (map[x][j] == cur) y_list.push_back(j);
	}

	for (int i = 0; i < x_list.size(); i++) {
		for (int j = 0; j < y_list.size(); j++) {
			if (cur == 5) {
				//cout << x_list[i] << " " << y_list[j] << endl;
			}
			int cur_x = x_list[i];
			int cur_y = y_list[j];

			if ((cur_x - x) != (cur_y - y)) continue;

			if (map[cur_x][cur_y] == cur) {
				//cout << "정답" << cur_x << " " << cur_y << endl;
				//점은 4개여야 함
				if (x == cur_x || y == cur_y) continue;

				int k = ((cur_x - x) + 1) * ((cur_y - y) + 1);
				result = max(result, k);
			}

		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			map[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//아직 방문한 적이 없는 숫자면 진행
			solve(map[i][j],i,j);
		}
	}

	cout << result;

	return 0;
}