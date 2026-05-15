#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

queue<int> pq;

int ponketmon[200001];

int solution(vector<int> nums)
{
    int answer = 0;
    //N마리 포켓몬 중에서 N/2 마리를 가져가도 된다.
    
    //최대한 많은 종류의 포켓몬을 가지고싶다.
    //포켓몬 종류 번호의 개수를 return;
    
    //최대한 많은 종류를 가질려면 nums에서 
    
    for(int i = 0; i<nums.size(); i++){
        ponketmon[nums[i]] += 1;
    }
    
    for(int i = 0; i<200001; i++){
        if(ponketmon[i] != 0)
            pq.push(ponketmon[i]);
    }
    
    while(!pq.empty()){
        answer += 1;
        pq.pop();
    }
    
    if(answer > nums.size() / 2) answer = nums.size() / 2;
    
    return answer;
}