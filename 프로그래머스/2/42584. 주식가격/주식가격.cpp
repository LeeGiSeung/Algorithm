#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for(int i = 0; i<prices.size(); i++){
        int chx = 0;
        for(int j = i + 1; j<prices.size(); j++){
            chx++;
            if(prices[j] < prices[i]) break;
        }
        answer.push_back(chx);
    }
    
    return answer;
}