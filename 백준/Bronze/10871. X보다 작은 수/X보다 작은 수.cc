#include <iostream>


using namespace std;
int main() {

	int n, x;
	cin >> n >> x;
	int arr[10000];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];		// 배열에 N개의 수를 저장
	}

	for (int i = 0; i < n; i++) {
		// i번째 원소가 X보다 작다면 출력
		if (arr[i] < x) {
			cout << arr[i] << " ";
		}
	}
}
