#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2,0);
    int minrange = 1e9;
    //모든 보석을 하나 이상 포함하는 가장 짧은 구간을 찾아서 return
    set<string> s;
    for(string i : gems) s.insert(i);
    
    int gem = s.size();
    
    int n = gems.size();
    map<string,int> m;
    
    
    int start = 0;
    for(int end = 0; end < n; end++){
        m[gems[end]]++;
        
        while(m.size() == gem){
            if(end - start < minrange){
                minrange = end - start;
                answer[0] = start + 1;
                answer[1] = end + 1;
            }
            
            m[gems[start]]--;

            if(m[gems[start]] == 0){
                m.erase(gems[start]);
            }

            start++;
        }
    }
    
    return answer;
}