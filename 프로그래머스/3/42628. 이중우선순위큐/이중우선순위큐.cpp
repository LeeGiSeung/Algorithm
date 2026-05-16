#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2,0);
    multiset<int> set;
    
    for(int i = 0; i<operations.size(); i++){
        string s = operations[i];
        
        if(s[0] == 'I'){
            int num = stoi(s.substr(2, s.size()));
            set.insert(num);
        }
        else if(s[0] == 'D'){
            if(set.size() == 0) continue;
            if(s[2] == '-'){
                set.erase(set.begin());
            }
            else{
                set.erase(prev(set.end()));
            }
        }
    }
    
    if(set.size() == 0){
        answer[0] = 0;
        answer[1] = 0;
    }
    else{
        answer[0] = *prev(set.end());
        answer[1] = *set.begin();
    }
    
    return answer;
}