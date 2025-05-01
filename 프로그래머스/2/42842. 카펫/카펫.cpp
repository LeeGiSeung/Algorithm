#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    //brown	yellow
    //10 2      [4, 3]
    //8	 1      [3, 3]
    //24 24     [8, 6]

    int tile = brown + yellow;
    int width = 3;
    int height = 0;

    while (true) {
        if (tile % width == 0) {
            height = tile / width;
            if (width >= height && ((width - 2) * (height - 2) == yellow)) {
                answer.push_back(width);
                answer.push_back(height);
                break;
            }
            else {
                width++;
            }
        }
        else {
            width++;
        }
    }

    return answer;
}

int main() {
    solution(10, 2);

    return 0;
}