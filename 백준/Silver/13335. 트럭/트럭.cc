#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int n, w, l, a, result, bridge, success_truck;

deque<pair<int, int>> bridge_queue;
queue<pair<int,int>> q;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> w >> l;
	result = 1;
	for (int i = 0; i < n; i++) {
		cin >> a;
		q.push({ a,0 });
	}

	while (success_truck != n) {
		//다리에 올릴 수 있는 상황이면 트럭을 다리 위로 올린다. 지나갈 수 있는 트럭이 남아있을때만

		if (!q.empty()) {
			if(bridge + q.front().first <= l) {
				bridge += q.front().first;
				bridge_queue.push_back({ q.front().first, q.front().second });
				q.pop();
			}
		}


		//현재 다리위에 올라와있는 트럭들 크기 증가
		for (int i = 0; i < bridge_queue.size(); i++) {
			bridge_queue[i].second += 1;
		}

		//다리 위에 존재했던 시간이 정해놓은 것보다 길어졌을때 사라짐
		if (!bridge_queue.empty()) {
			if (bridge_queue.front().second >= w) {
				bridge -= bridge_queue.front().first;
				bridge_queue.pop_front();
				success_truck++;
			}
		}

		result++;
	}

	cout << result;

	return 0;
}