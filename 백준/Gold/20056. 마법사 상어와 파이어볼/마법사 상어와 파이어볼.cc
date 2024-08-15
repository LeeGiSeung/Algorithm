#include <iostream>
#include <queue>

using namespace std;

struct FIREBALL
{
	int x;
	int y;
	int kg;
	int speed;
	int direct;
};

vector<FIREBALL>map[55][55];
vector<FIREBALL> Fire_ball;


int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
int holl[4] = { 1,3,5,7 };
int jjak[4] = { 0,2,4,6 };

int n, m, k;

void MoveFireBall() {

	for (int i = 1; i <= n; i++)
	{
	for (int j = 1; j <= n; j++)
		{
			map[i][j].clear();
		}
	}

	int c = Fire_ball.size();
	for (int i = 0; i < c; i++) {

		int nx = Fire_ball[i].x;
		int ny = Fire_ball[i].y;
		int nkg = Fire_ball[i].kg;
		int nspeed = Fire_ball[i].speed;
		int ndirect = Fire_ball[i].direct;


		int move = nspeed % n;

		nx = nx + dx[ndirect] * move;
		ny = ny + dy[ndirect] * move;

		if (nx > n) nx -= n;
		if (ny > n) ny -= n;
		if (nx < 1) nx += n;
		if (ny < 1) ny += n;

		map[nx][ny].push_back({ nx,ny,nkg,nspeed,ndirect });

		Fire_ball[i].x = nx;
		Fire_ball[i].y = ny;
 	}	
}

void SumFireBall() {
	vector<FIREBALL> temp;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j].size() == 0) {
				continue;
			}
			if (map[i][j].size() == 1) {
				temp.push_back(map[i][j][0]);
				continue;
			}

			int kg_sum = 0;
			int speed_sum = 0;

			bool ho = true;
			bool ja = true;

			for (int z = 0; z < map[i][j].size(); z++) {
				kg_sum += map[i][j][z].kg;
				speed_sum += map[i][j][z].speed;

				if (map[i][j][z].direct % 2 == 0) ja = false;
				else ho = false;
			}

			int kg_sum_5 = kg_sum / 5;
			int speed_sum_f = speed_sum / map[i][j].size();

			if (kg_sum_5 == 0) {
				continue;
			}
			if (ho == true || ja == true) {
				//홀수
				for (int b = 0; b < 4; b++) {
					temp.push_back({ i,j,kg_sum_5,speed_sum_f,jjak[b] });
				}
			}
			else {
				for (int b = 0; b < 4; b++) {
					temp.push_back({ i,j,kg_sum_5,speed_sum_f,holl[b] });
				}
			}
		}
	}
	Fire_ball = temp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		//위치 (r, c)는 r행 c열을 의미한다 질량은 mi이고, 속력은 si이다, 방향은 di
		int ri, ci, mi, si, di;
		cin >> ri >> ci >> mi >> si >> di;
		Fire_ball.push_back({ ri,ci,mi,si,di });
		map[ri][ci].push_back({ ri,ci,mi,si,di });
	}

	for (int a = 0; a < k; a++)
	{
		MoveFireBall();
		SumFireBall();
	}

	int answer = 0;

	for (int i = 0; i < Fire_ball.size(); i++) {
		answer += Fire_ball[i].kg;
	}

	cout << answer;

	return 0;
}