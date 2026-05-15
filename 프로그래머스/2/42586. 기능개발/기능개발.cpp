#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Info {
    int index;
    int progress;
    bool done;
    
    Info(int _index, int _progress, bool _done) {
        index = _index;
        progress = _progress;
        done = _done;
    }
};

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<Info> q;
    
    for(int i = 0; i < progresses.size(); i++) {
        q.push(Info(i, progresses[i], false));
    }

    int comIndex = -1; // 현재까지 배포 완료된 마지막 인덱스
    
    while(!q.empty()) {
        
        // 1. 현재 큐에 들어있는 '하루치 작업 분량'만큼만 돌리기 위해 size를 고정합니다.
        int current_day_size = q.size();
        
        for(int i = 0; i < current_day_size; i++) {
            Info curInfo = q.front();
            q.pop();
            
            // 아직 완료되지 않은 작업이라면 진도를 더해줌
            if (!curInfo.done) {
                curInfo.progress += speeds[curInfo.index];
                if (curInfo.progress >= 100) {
                    curInfo.done = true; // 100% 채우면 완료 마크!
                }
            }
            
            // 작업 강도와 상관없이, 일단 하루치 계산이 끝난 데이터는 다시 큐의 뒤로 넣음
            q.push(curInfo);
        }
        
        // 2. 하루 일과(모든 작업 진도 추가)가 끝난 시점에 맨 앞을 확인합니다.
        // 배포 순서가 된 선두 작업이 이미 완료(done == true) 상태라면? 연속 배ポ 시작!
        int deploy_count = 0;
        
        while(!q.empty() && q.front().done && q.front().index - 1 == comIndex) {
            deploy_count++;
            comIndex++;  // 기준 인덱스 상승
            q.pop();     // 질문자님이 원하셨던 큐에서의 실제 delete(pop)
        }
        
        // 오늘 배포한 기능이 있다면 answer에 기록
        if (deploy_count > 0) {
            answer.push_back(deploy_count);
        }
    }
    
    return answer;
}