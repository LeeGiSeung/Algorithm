#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long solution(vector<int> sequence) {
    
    long long answer = 0;
    long long m_ans = 0;
    long long p_ans = 0;
    
    for(int i = 0; i<sequence.size(); i++){
        int sign = (i % 2 == 0) ? 1 : -1;
        int sign2 = -sign;
        
        m_ans = max(m_ans + 1LL * sequence[i] * sign2, 1LL * sequence[i] * sign2);
        p_ans = max(p_ans + 1LL * sequence[i] * sign, 1LL * sequence[i] * sign);
        
        answer = max({answer, m_ans, p_ans});
    }
    

    
    return answer;
}