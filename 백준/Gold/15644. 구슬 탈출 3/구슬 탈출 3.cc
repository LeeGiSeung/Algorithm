#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

//BEAD구조체에 빨,파 의 좌표값과 경로를 저장함
struct BEAD
{
	int redX = 0;
	int redY = 0;
	int blueX = 0;
	int blueY = 0;
	int count = 0;
	string Track;
};

BEAD cur;

int n, m;

int map[10][10];

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'R') {
				cur.redX = i;
				cur.redY = j;
			}
			else if (s[j] == 'B') {
				cur.blueX = i;
				cur.blueY = j;
			}
			map[i][j] = s[j];
		}
	}
}

int MoveRed(int &x, int &y, int dir) {
	int count = 0;
	//벽에 닿지 않을 때 까지 반복
	while (map[x + dx[dir]][y+dy[dir]] != '#') {
		x += dx[dir];
		y += dy[dir];
		count++;
		if (map[x][y] == 'O') return count;
		//만약 빨강 구슬이 'O'에 접근 했을 경우 count return;
	}
	return count;
	//빨강 구슬이 'O'에 접근하지 않았더라도 벽에 닿으면 while이 break되면서 움직인 count return;
}

int MoveBlue(int &x, int &y, int dir) {
	int count = 0;
	//벽에 닿지 않을 때 까지 반복
	while (map[x + dx[dir]][y + dy[dir]] != '#') {
		x += dx[dir];
		y += dy[dir];
		count++;
		//만약 파랑 구슬이 'O'에 접근 했을 경우 -1 return 해서 끊음
		if (map[x][y] == 'O') return -1;
	}
	return count;
	//파랑 구슬이 'O'에 접근하지 않았더라도 벽에 닿으면 while이 break되면서 움직인 count return;
}
//왼쪽으로 기울이기는 'L', 오른쪽으로 기울이기는 'R', 위로 기울이기는 'U', 아래로 기울이기는 'D'로 출력하며
char direction[4] = { 'U','D','L','R' };

//빨파가 같은 위치에 있는 경우는 다시 갈 필요 없음, 한쪽만 true인건 상관 없다.

bool check[10][10][10][10] = { false };

int result = 100000000;

void solve() {
	queue<BEAD> q;

	q.push({ cur.redX,cur.redY, cur.blueX, cur.blueY,0 });

	while (!q.empty()) {

		int credX = q.front().redX;
		int credY = q.front().redY;
		int cblueX = q.front().blueX;
		int cblueY = q.front().blueY;
		int count = q.front().count;
		//cout << "빨" << redX << " " << redY << " 파" << blueX << " " << blueY << endl;
		string ctrack = q.front().Track;
		q.pop();


		if (count >= 10) {
			break;
		}

			for (int i = 0; i < 4; i++) {
				//count로 알 수 있는건 빨강 구슬과 파랑 구슬의 이동과 각 구슬이 이동한 값을 구해서 만약 두 구슬의 위치가 같을 경우 이동 위치가 더 큰 구슬이 뒤에 있다는 거니까 적은 구슬 바로 -dx[i] -dy[i] 칸에 위치주면 됨
				int redX = credX;
				int redY = credY;
				int blueX = cblueX;
				int blueY = cblueY;
				int ncount = count + 1;
				string track = ctrack;

				//그리고 만약 움직였는데 blueCount가 -1로 리턴 된다면 이건 O에 들어가 안되는 재귀니 실행하면 안된다.
				int redCount = MoveRed(redX, redY, i);
				int blueCount = MoveBlue(blueX, blueY, i);

				track += direction[i];

				if (blueCount == -1 ) continue;
				if (map[redX][redY] == 'O') {
					cout << track.size() << "\n";
					cout << track;
					return;
				}

				//움직이는건 다 확인했으니 check값으로 이미 방문했던 기록이 있는지 확인한다. blueCount가 -1은 파랑 구슬이 'O' 안에 들어갔다는 것임 

				//cout << i << "됨" << endl;
				//만약 red위치하고 blue위치가 같은 위치에 있을 경우에 더 많이 움직인 구슬이 대상 구슬보다 뒤에 있었을 테니까 dx[i] dy[i] 만큼 빼줘야함
				if (redX == blueX && redY == blueY) {
					if (redCount > blueCount) {
						redX -= dx[i];
						redY -= dy[i];
					}
					else if (blueCount > redCount) {
						blueX -= dx[i];
						blueY -= dy[i];
					}
				}
				if (check[redX][redY][blueX][blueY] == true) continue;
				check[redX][redY][blueX][blueY] = true;
				q.push({ redX,redY,blueX,blueY,ncount,track });
			}
		}
	cout << -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solve();

	return 0;
}
