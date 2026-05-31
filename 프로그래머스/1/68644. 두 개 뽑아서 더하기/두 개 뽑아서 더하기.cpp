#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

vector<int> solution(vector<int> numbers) {
    
    
    sort(numbers.begin(), numbers.end());
    
    set<int> ans;
    
    for(int i = 0; i<numbers.size() - 1; i++){
        for(int j = i + 1; j<numbers.size(); j++){
            ans.insert(numbers[i] + numbers[j]);
        }
    }
    
    vector<int> answer(ans.begin(), ans.end());
    
    return answer;
}