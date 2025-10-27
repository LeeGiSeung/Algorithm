#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct Data {
    int start;
    int dist;
    bool operator<(const Data& a) const {
        return dist > a.dist; // 소요 시간이 짧은 순으로
    }
};

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end()); // 시작 시간 기준 정렬
    priority_queue<Data> pq;
    
    int time = 0;
    int index = 0;
    int total = 0;
    int count = 0;
    
    while (count < jobs.size()) {
        // 현재 시간에 들어온 작업들 추가
        while (index < jobs.size() && jobs[index][0] <= time) {
            pq.push({ jobs[index][0], jobs[index][1] });
            index++;
        }

        if (!pq.empty()) {
            Data cur = pq.top();
            pq.pop();
            time += cur.dist; // 작업 진행
            total += time - cur.start; // 완료 시간 - 요청 시간
            count++;
        } else {
            // 대기 중인 작업이 없으면 다음 작업이 들어올 때까지 시간 이동
            time = jobs[index][0];
        }
    }

    return total / jobs.size();
}
