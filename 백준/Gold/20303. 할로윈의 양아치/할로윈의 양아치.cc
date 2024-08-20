#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <ctime>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX_N 30001
#define MAX_K 3001
#define LL long long
#define INF 1e9

using namespace std;
int N, M, K;
int C[MAX_N];
int Parent[MAX_N];
vector<int> Friends[MAX_N];
int All_Candy[MAX_N];
int DP[MAX_N][MAX_K];
int Answer = 0;

void Init() {
	for (int i = 1; i < MAX_N; i++) {
		Parent[i] = i;
	}
}

int Find(int X) {
	if (Parent[X] == X) {
		return X;
	}
	return Parent[X] = Find(Parent[X]);
}

void Union(int X, int Y) {
	int PX = Find(X);
	int PY = Find(Y);
	if (PX <= PY) {
		Parent[PY] = PX;
	}
	else {
		Parent[PX] = PY;
	}
}

void Input() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> C[i];
	}
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		Union(A, B);
	}
}

void Settings() {
	vector<int> Vec;
	for (int i = 1; i <= N; i++) {
		int P = Find(i);
		Friends[P].push_back(i);
		Vec.push_back(P);
	}
	sort(Vec.begin(), Vec.end());
	Vec.erase(unique(Vec.begin(), Vec.end()), Vec.end());
	for (int i = 0; i < Vec.size(); i++) {
		int Rep = Vec[i];
		for (int j = 0; j < Friends[Rep].size(); j++) {
			All_Candy[i] += C[Friends[Rep][j]];
		}
	}
	for (int i = 0; i < Vec.size(); i++) {
		int Cur = Vec[i];
		int Cnt = Friends[Cur].size();
		int Candy = All_Candy[i];
		for (int j = (K - 1); j >= 0; j--) {
			if (j - Cnt >= 0) {
				DP[i + 1][j] = max(DP[i][j], DP[i][j - Cnt] + Candy);
			}
			else {
				DP[i + 1][j] = DP[i][j];
			}
			Answer = max(Answer, DP[i + 1][j]);
		}
	}
}

void Find_Answer() {
	cout << Answer << "\n";
}

int main() {
	FASTIO
	Init();
	Input();
	Settings();
	Find_Answer();

	return 0;
}