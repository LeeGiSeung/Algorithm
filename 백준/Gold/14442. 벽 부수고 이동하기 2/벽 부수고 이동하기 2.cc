#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int height, width, k;

bool check[11][1001][1001];
int map[1001][1001];
int result = -1;

struct DATA {
	int height;
	int width;
	int breakwall;
	int ti;
};

int dheight[4] = { -1,1,0,0 };
int dwidth[4] = { 0,0,-1,1 };

void solve(int _height, int _widht, int _k) {
	queue<DATA> q;
	q.push({ _height,_widht,_k,1 });
	check[_k][_height][_widht] = true;
	while (!q.empty()) {
		int curheight = q.front().height;
		int curwidth = q.front().width;
		int breakwall = q.front().breakwall;
		int ti = q.front().ti;
		q.pop();
		if (curheight == height && curwidth == width) {
			result = ti;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nheight = curheight + dheight[i];
			int nwidth = curwidth + dwidth[i];
			if (1 <= nheight && nheight <= height && 1 <= nwidth && nwidth <= width) {
				if (check[breakwall][nheight][nwidth] == false) {
					//벽이 존재 할때
					if (map[nheight][nwidth] == 1) {
						//벽을 부술 수 있는 횟수가 남아있을때
						if (breakwall > 0) {
							//아직 벽을 부순 경우의 수를 방문하지 않았을 때
							if (check[breakwall - 1][nheight][nwidth] == false) {

								check[breakwall - 1][nheight][nwidth] = true;

								q.push({ nheight,nwidth,breakwall - 1,ti + 1 });
							}
						}
					}
					//벽이 있지 않을때
					else if (map[nheight][nwidth] == 0) {

						check[breakwall][nheight][nwidth] = true;

						q.push({ nheight,nwidth,breakwall,ti + 1 });
					}
				}
			}
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> height >> width >> k;
	for (int i = 1; i <= height; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= width; j++) {
			map[i][j] = s[j - 1] - '0';
		}
	}

	solve(1, 1, k);
	cout << result;
	return 0;
}