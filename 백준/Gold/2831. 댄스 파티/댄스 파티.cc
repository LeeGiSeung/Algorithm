#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int N;
int COUNT;

vector<int> NEG_MAN;
vector<int> NEG_WOMAN;
vector<int> POS_MAN;
vector<int> POS_WOMAN;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int MAN_INDEX = 0;
	int WOMAN_INDEX = 0;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (a < 0) {
			NEG_MAN.push_back(abs(a));
		}
		else {
			POS_MAN.push_back(a);
		}
		
	}
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (a < 0) {
			NEG_WOMAN.push_back(abs(a));
		}
		else {
			POS_WOMAN.push_back(a);
		}
	}
	
	sort(NEG_MAN.begin(), NEG_MAN.end(), greater<int>());
	sort(POS_MAN.begin(), POS_MAN.end(), greater<int>());
	sort(NEG_WOMAN.begin(), NEG_WOMAN.end(), greater<int>());
	sort(POS_WOMAN.begin(), POS_WOMAN.end(), greater<int>());

	WOMAN_INDEX = 0;
	MAN_INDEX = 0;
	//남자 음수 
	//여자는 남자보다 작아야함
	while (MAN_INDEX < NEG_MAN.size() && WOMAN_INDEX < POS_WOMAN.size()) {
		if (NEG_MAN[MAN_INDEX] > POS_WOMAN[WOMAN_INDEX]) {
			COUNT++;
			WOMAN_INDEX++;
			MAN_INDEX++;
		}
		else {
			WOMAN_INDEX++;
		}
	}

	WOMAN_INDEX = 0;
	MAN_INDEX = 0;
	//남자 양수
	//여자는 남자보다 커야함
	while (MAN_INDEX < POS_MAN.size() && WOMAN_INDEX < NEG_WOMAN.size()) {
		if (POS_MAN[MAN_INDEX] < NEG_WOMAN[WOMAN_INDEX]) {
			COUNT++;
			WOMAN_INDEX++;
			MAN_INDEX++;
		}
		else {
			MAN_INDEX++;
		}
	}

	cout << COUNT;

	return 0;
}
