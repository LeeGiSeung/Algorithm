#include <string>
#include <vector>

using namespace std;

bool check[1000001];

int solution(vector<int> elements) {
    int answer = 0;

    int length = elements.size();

    for (int i = 0; i < length; i++) { //0~n개의 경우
        int sum = 0;
        for (int j = i; j < i + length; j++) { //j번째 숫자에서 1개~n개를 합치는 경우의 수
            int index = j % length;
            sum += elements[index];
            if (check[sum] == false) {
                check[sum] = true;
                answer++;
            }
        }
    }

    return answer;
}

int main() {
    vector<int> v{ 7,9,1,1,4 };
    solution(v);
}