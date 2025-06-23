#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    multiset<int> ms;
    
    for(int i = 0; i<operations.size(); i++){
        string s = operations[i];
        
        if(s.find("I") == 0){
            int a = stoi(s.substr(s.find(" ") + 1));
            //cout<<a<<endl;
            ms.insert(a);
        }
        else if(s.find("D 1") == 0 && ms.size() != 0){
            ms.erase(--ms.end());
        }
        else if(s.find("D -1") == 0 && ms.size() != 0){
            ms.erase(ms.begin());
        }
    }
    
    if(ms.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(*ms.rbegin());
        answer.push_back(*ms.begin());
    }
    
    return answer;
}