#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 1e8;
    
    //현재 퍼즐의 난이도를 diff
    //현재 퍼즐의 소요 시간을 time_cur
    //이전 퍼즐의 소요 시간을 time_prev
    //당신의 숙련도를 level
    int left = 1;
    int right = 100000;
    long long alltime = 0;
    //제한 시간 내에 퍼즐을 모두 해결할 수 있는 경우만 입력으로 주어집니다.
    while(left <= right){ //아직 답이 안나왔으면 찾음
        int mid = (left + right) / 2; //mid가 Level임
        
        alltime = 0;
        int time_cur = 0;
        int time_prev = 0;
        
        for(int i = 0; i<diffs.size(); i++){
            time_cur = times[i];
            //1. diff ≤ level이면 퍼즐을 틀리지 않고 time_cur만큼의 시간을 사용하여 해결합니다.
            if(diffs[i] <= mid){
                alltime += time_cur;
            }
            //2.diff > level이면, 
            else if(diffs[i] > mid){
                //퍼즐을 총 diff - level번 틀립니다.
                int count = diffs[i] - mid; //count = 퍼즐을 틀린 횟수
                alltime += (time_cur * count) + (time_prev * count);
                // 퍼즐을 틀릴 때마다, time_cur만큼의 시간을 사용하며, 추가로 time_prev만큼의 시간을 사용해 이전 퍼즐을    다시 풀고 와야 합니다.
                
                //이전 퍼즐을 다시 풀 때는 이전 퍼즐의 난이도에 상관없이 틀리지 않습니다.
                
                //3. diff - level번 틀린 이후에 다시 퍼즐을 풀면 time_cur만큼의 시간을 사용하여 퍼즐을 해결
                alltime += time_cur;
            }
            time_prev = time_cur;
        }
        
        //alltime : 현재 난이도에서 계산한 시간
        
        if(alltime <= limit){ //alltime이 limit보다 작으면 저 줄여봐도 됨
            right = mid - 1;
            answer = mid;
        }
        else{
            left = mid + 1;
        }
    }

    
    //숙련도의 최소값을 구하는거다 limit 아래로 시간이 되는
    
    return answer;
}