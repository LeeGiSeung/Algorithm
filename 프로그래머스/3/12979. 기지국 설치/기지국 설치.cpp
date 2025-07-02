#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int location = 1;
    int range = w * 2 +1;
    
    for(int i = 0; i<stations.size(); i++){
        int left = stations[i] - w;
        int right = stations[i] + w;
        
        if(left > location){
            int gap = left - location;
            answer += (gap + range - 1) / range;
        }
        
        location = right + 1;
    }
    
    if(location <= n){
        int gap = n - location + 1;
        answer += (gap + range - 1) / range;
    }
    
    return answer;
}