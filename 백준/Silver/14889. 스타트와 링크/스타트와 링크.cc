#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int n;
int soccer [22][22];
deque<int> start;
deque<int> link;
int start_result = 0, link_result = 0, result = 100000000;
bool visit[25];

void DFS(int x, int pos) // x는 카운트 수, pos는 다음 값
{
	if (x == n / 2) // 카운트수가 정원의 1/2이 됐을 때 능력치합 계산
	{
		int start, link;
		start = 0;
		link = 0;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (visit[i] == true && visit[j] == true) start += soccer[i][j];
				if (visit[i] == false && visit[j] == false) link += soccer[i][j];
			}
		}

		int temp = abs(start - link);
		if (result > temp) result = temp;

		return;
	}

	for (int i = pos; i < n; i++)
	{
		visit[i] = true;
		DFS(x + 1, i + 1);
		visit[i] = false;
	}

}


int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
			cin >> soccer[i][j];
        }
    }

	DFS(0, 1);

    cout << result << "\n";

    return 0;

}