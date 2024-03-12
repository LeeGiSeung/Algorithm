#include <bits/stdc++.h>

using namespace std;

int R, C, answer;
int dr[4] = { -1, 1, 0 , 0 };
int dc[4] = { 0, 0, -1 , 1 };
char board[20][20];
bool visited[26]; // 알파벳 별 방문 체크 (현재의 경로 기준이므로 성공이든 실패든 재귀 함수가 호출을 끝내고 돌아오면 다시 false 로 바꿔 방문 체크를 해제해준다.)

void dfs(int r, int c, int dist) {
	
	bool canGo = false;
	for (int i = 0; i < 4; ++i) {
		int nextR = r + dr[i];
		int nextC = c + dc[i];

		if (nextR < 0 || nextR >= R || nextC < 0 || nextC >= C) continue; // 갈 수 없는 곳 1 (보드 범위를 넘어섬)
		char nextAlpha = board[nextR][nextC];
		if (visited[nextAlpha - 'A']) continue; // 갈 수 없는 곳 2 (현재의 경로 내에서 이전에 방문했었던 알파벳)

		canGo = true; // 갈 수 있는 곳 하나라도 발견했다면 true
		visited[nextAlpha - 'A'] = true;
		dfs(nextR, nextC, dist + 1);
		visited[nextAlpha - 'A'] = false; // ⭐ 또 다른 경로에서 해당 알파벳이 다시 선택될 수 있도록
	}

	if (!canGo) { // 더 이상 갈 수 있는 곳이 없다면! (즉, for문에서 재귀 한번도 못 돌림. 더 이상 나아갈 경로가 없음)
		answer = max(answer, dist);
		return;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			cin >> board[i][j];

	char nextAlpha = board[0][0];
	visited[nextAlpha - 'A'] = true; // 출발 지점 체크
	dfs(0, 0, 1); // 문제에서 시작점도 카운팅에 포함된다고 했으므로 1 에서 시작
	
	cout << answer;
}