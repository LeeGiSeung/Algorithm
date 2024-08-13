#include <iostream>

int N, M, m[100], c[100], dp[101][10001];

int max(int a, int b) {
	if (a > b) return a;
	return b;
}

int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);

	// 값 입력받기
	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		std::cin >> m[i];
	}
	
	for (int i = 0; i < N; i++) {
		std::cin >> c[i];
	}

	// N개의 앱에 대해서
	for (int i = 0; i < N; i++) {
		// 최대 10000의 소요시간이 걸린다
		//각 소요시간에 대해서 얻을 수 있는 최대 메모리 계산
		for (int j = 0; j < 10001; j++) {
			// 현재 앱의 소요시간이 탐색하는 소요시간보다 크면 비활성화 불가
			// 이전 dp의 값을 받아옴
			if (c[i] > j) dp[i+1][j] = dp[i][j];
			// 현재 앱의 소요시간이 탐색하는 소요시간보다 작으면 dp체크
			// 비활성화인 경우 dp[i][j-c[i]] + m[i], 활성화 일경우 dp[i][j]
			// 두 값중 큰 값 저장
			else {
				dp[i+1][j] = max(dp[i][j], dp[i][j - c[i]]+m[i]);
 			}
		}
	}


	// 소요시간별로 메모리가 M이상이면 출력 후 종료
	for (int i = 0; i < 10001; i++) {
		if (dp[N][i] >= M) {
			std::cout << i;
			break;

		}
	}

	return 0;
}