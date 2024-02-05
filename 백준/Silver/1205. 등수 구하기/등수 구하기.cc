#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int N, score, P;
	cin >> N >> score >> P;
	
	int rank = 1;
	int input;
	deque<int> q;


	for (int i = 0; i < N; i++) {
		cin >> input;
		q.push_back(input);
	}

	if (N == P && q.back() >= score) {
		cout << -1;
	}
	else {
		while (1) {
			if (q.front() > score) {
				rank++;
				q.pop_front();
			}
			else {
				break;
			}
		}
		cout << rank;
	}


    return 0;
}