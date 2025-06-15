#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 1e8;
    
    //취약 지점의 위치는 정북 방향 지점으로부터 시계 방향으로 떨어진 거리
    //친구들은 출발 지점부터 시계, 혹은 반시계 방향으로 외벽을 따라서만 이동

    sort(dist.begin(), dist.end());
    
    int size_w = weak.size();
    
    for(int i = 0; i<size_w - 1; i++){
        weak.push_back(weak[i] + n);
    }
    
    do{
        for(int i = 0; i<size_w; i++){
            int start = weak[i];
            int end = weak[size_w + i - 1];
            //start 지점과 end 지점 설정
            for(int j = 0; j<dist.size(); j++){
                start += dist[j];
                
                if(start >= end)
                {
                    answer = min(answer, j + 1);
                    break;
                }
                for(int z = i + 1; z<weak.size(); z++){
                    if(weak[z] > start){
                        start = weak[z];
                        break;
                    }
                }
            }
        }
    }while(next_permutation(dist.begin(), dist.end()));

    if(answer == 1e8) return -1;
    
    return answer;
}