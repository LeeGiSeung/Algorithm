#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//어떤 과학자가 발표한 논문 n편 중, h번 이상 인용된 논문이 h편 이상

#include <string>
#include <vector>

using namespace std;

struct DATA {
    int progress;
    int speed;
    int day;
};

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int day = 1;

    queue<int> q;

    for (int i = 0; i < progresses.size(); i++) {
        q.push(progresses[i]);
    }

    int index = 0;


    while(!q.empty()){
        int count = 0;
        while (progresses[index] >= 100) {
            index++;
            count++;
            q.pop();
            if (index >= progresses.size())
            {
                break;
            }
        }

        if (count != 0) { //사라진게 있으면 결과에 추가
            answer.push_back(count);
        }

        for (int i = index; i < progresses.size(); i++) {
            progresses[i] += speeds[i];
        }
    }

    return answer;
}

int main() {

    vector<int> a = { 30,30,30 };
    vector<int> b = { 30,30,30 };

    solution(a,b);
}