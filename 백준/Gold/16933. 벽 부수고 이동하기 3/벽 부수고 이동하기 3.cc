#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int height, width, k;

bool check[2][11][1001][1001];
int map[1001][1001];
int result = -1;
//낮 밤 처음에는 낮
bool day = true;
struct DATA {
	int height;
	int width;
	int breakwall;
	int ti;
};

int dheight[4] = { -1,1,0,0 };
int dwidth[4] = { 0,0,-1,1 };
//낮, 밤 추가된다.
//벽은 낮에만 부술 수 있다.
//이동은 밤에도 가능하다.
//이동하지 않고 하루를 보내는 경우의 수도 존재한다.
void solve(int _height, int _widht, int _k) {
	queue<DATA> q;
	q.push({ _height,_widht,_k,1 });
	check[day][_k][_height][_widht] = true;
	int curheight;
	int curwidth;
	int breakwall;
	int ti;
	while (true) {
		int qsize = q.size();
		//이동
		if (qsize == 0) {
			return;
		}
		for (int z = 0; z < qsize; z++) {

			curheight = q.front().height;
			curwidth = q.front().width;
			breakwall = q.front().breakwall;
			ti = q.front().ti;
			q.pop();

			if (curheight == height && curwidth == width) {
				result = ti;
				return;
			}

			for (int i = 0; i < 4; i++) {
				int nheight = curheight + dheight[i];
				int nwidth = curwidth + dwidth[i];
				if (1 <= nheight && nheight <= height && 1 <= nwidth && nwidth <= width) {
					if (check[day][breakwall][nheight][nwidth] == false) {
						//벽이 존재 할때
						if (map[nheight][nwidth] == 1) {
							if (day == true) {
								//벽을 부술 수 있는 횟수가 남아있을때
								if (breakwall > 0) {
									//아직 벽을 부순 경우의 수를 방문하지 않았을 때
									if (check[day][breakwall - 1][nheight][nwidth] == false) {
										check[day][breakwall - 1][nheight][nwidth] = true;

										q.push({ nheight,nwidth,breakwall - 1,ti + 1 });
									}
								}
							}
						}
						//벽이 있지 않을때
						else if (map[nheight][nwidth] == 0) {
							check[day][breakwall][nheight][nwidth] = true;

							q.push({ nheight,nwidth,breakwall,ti + 1 });
						}
					}
				}
			}
			//이동 하지 않는 경우의 수 추가
			if (check[day][breakwall][curheight][curwidth] == false) {
				check[day][breakwall][curheight][curwidth] = true;
				q.push({ curheight,curwidth,breakwall,ti + 1 });
			}
		}

		if (day == true) {
			day = false;
		}
		else {
			day = true;
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