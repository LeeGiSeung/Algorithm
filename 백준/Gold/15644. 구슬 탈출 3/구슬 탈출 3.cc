#include<iostream>
#include<queue>
#define endl "\n"
using namespace std;

struct step
{
	int Rx, Ry; // 빨간공
	int Bx, By; // 파란공
	int Count;  // 움직인 수
	string Log;
};

char map[11][11];
bool visit[11][11][11][11];
int N, M;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void move(int& rx, int& ry, int& distance, int& i)
{
	while (map[rx + dx[i]][ry + dy[i]] != '#' && map[rx][ry] != 'O')
	{
		rx += dx[i];   // x 좌표 이동
		ry += dy[i];   // y 좌표 이동
		distance += 1; // 공이 움직인 거리
	}
}

void BFS(int Rx, int Ry, int Bx, int By)
{
	queue<step> q;
	q.push({ Rx,Ry,Bx,By,0,""});
	visit[Rx][Ry][Rx][Ry] = true;
	while (!q.empty())
	{
		int rx = q.front().Rx;
		int ry = q.front().Ry;
		int bx = q.front().Bx;
		int by = q.front().By;
		int count = q.front().Count;
		string log = q.front().Log;
		q.pop();

		if (count >= 10) break;

		for (int i = 0; i < 4; i++)
		{
			int nrx = rx, nry = ry, nbx = bx, nby = by;
			int rc = 0, bc = 0, ncount = count + 1;
			string nlog = log;

			move(nrx, nry, rc, i);
			move(nbx, nby, bc, i);

			if (i == 0) nlog += "D";
			else if (i == 1) nlog += "U";
			else if (i == 2) nlog += "R";
			else nlog += "L";

			if (map[nbx][nby] == 'O') continue;
			if (map[nrx][nry] == 'O')
			{
				cout << ncount << endl;
				cout << nlog;
				return;
			}

			if (nrx == nbx && nry == nby)
			{
				if (rc > bc) nrx -= dx[i], nry -= dy[i];
				else nbx -= dx[i], nby -= dy[i];
			}

			if (visit[nrx][nry][nbx][nby]) continue;
			visit[nrx][nry][nbx][nby] = true;
			q.push({ nrx,nry,nbx,nby,ncount,nlog });
		}
	}
	cout << -1;
}

void Answer()
{
	cin >> N >> M;
	int Rx = 0, Ry = 0, Bx = 0, By = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'R')
			{
				Rx = i; Ry = j;
			}
			else if (map[i][j] == 'B')
			{
				Bx = i; By = j;
			}
		}
	}
	BFS(Rx, Ry, Bx, By);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	Answer();
	return 0;
}