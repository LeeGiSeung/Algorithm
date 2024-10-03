#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

struct DATA {
	int ti;
	int clip;
	int screen;
};

int check[2001][2001];

int s;
int result = 999999999;
//넓이 우선 방식
//queue에 시간, 클립보드, 화면을 가지고 있어야 할 것 같다.

void bfs() {

	queue<DATA> q;
	q.push({ 0,0,1 });

	while (!q.empty()) {
		int ti = q.front().ti;
		int clip = q.front().clip;
		int screen = q.front().screen;
		q.pop();

		if (screen == s) {
			cout << ti;
			return;
		}
		
		//화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장한다.
		//시간, 클립보드, 화면	
		if (!check[screen][screen] && screen <= 2000) {
			check[screen][screen] = true;
			q.push({ ti + 1,screen, screen });
		}
		
		//클립보드에 있는 모든 이모티콘을 화면에 붙여넣기 한다
		if (!check[clip][screen + clip]) {
			if (clip > 0 && screen + clip <= 2000) {
				check[clip][screen + clip] = true;
				q.push({ ti + 1,clip, screen + clip });
			}
		}
		
		//화면에 있는 이모티콘 중 하나를 삭제한다.
		if (!check[clip][screen - 1] && screen -1 >= 0) {
			check[clip][screen - 1] = true;
			q.push({ ti + 1,clip, screen-1});
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;

	bfs();

	return 0;
}