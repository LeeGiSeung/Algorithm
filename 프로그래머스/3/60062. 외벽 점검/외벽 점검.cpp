#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 1e8;
    int wallsize = weak.size();
    
    for(int i = 0; i<wallsize; i++){
        weak.push_back(weak[i] + n); //11시에서 1시로 가는 한바뀌 도는 것도 생각해야함
    }
    
    do{
        for(int i = 0; i<wallsize; i++){
            int startwall = weak[i];
            int endwall = weak[i + wallsize - 1];
            
            for(int j = 0; j<dist.size(); j++){
                startwall += dist[j];
                
                if(startwall >= endwall){ //dist 추가했는데 만약 endwall 넘으면 
                    answer = min(answer, j+1);
                    break;
                }
                
                //dist 더해진 startwall 기준으로 다음벽 검사
                for(int z = 0; z<weak.size(); z++){
                    if(startwall < weak[z]){
                        startwall = weak[z];
                        break;
                    }
                }
            }
        }
    }while(next_permutation(dist.begin(), dist.end()));
    
    //1, 5, 6, 10, 13, 17, 18
    
    //1, 3, 4, 9, 10, 13, 15, 16, 21
    
    if(answer == 1e8) answer = -1;
    
    return answer;
}