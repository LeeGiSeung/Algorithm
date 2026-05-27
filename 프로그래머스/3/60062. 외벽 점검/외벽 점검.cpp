#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 1e9;
    
    // 1. 원형 배열을 직선 배열로 확장 (weak 개수 2배로)
    int weak_size = weak.size();
    for (int i = 0; i < weak_size; i++) {
        weak.push_back(weak[i] + n);
    }
    
    sort(dist.begin(), dist.end());
    
    do {
        for (int i = 0; i < weak_size; i++) {
            int startIdx = i;
            int endIdx = i + weak_size - 1;
            
            int friendcount = 0;
            int nextStartIdx = startIdx;
            for(int j = 0; j<dist.size(); j++){
                friendcount++;
                int nextPoint = dist[j] + weak[nextStartIdx]; //다음 위치
                
                if(nextPoint >= weak[endIdx]){
                    answer = min(friendcount, answer);
                    break;
                }
                
                while(nextStartIdx <= endIdx && nextPoint >= weak[nextStartIdx]){
                    nextStartIdx++;
                }
                
                if(nextStartIdx > endIdx){
                    answer = min(friendcount, answer);
                    break;
                }
            }
        }
    } while (next_permutation(dist.begin(), dist.end()));
    
    return (answer == 1e9) ? -1 : answer;
}