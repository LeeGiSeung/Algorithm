#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    bool check = false;
    
    for(int i = 0; i<completion.size(); i++){
        if(participant[i] != completion[i]){
            cout<<participant[i];
            cout<<" 찾음"<<endl;
            check = true;
            answer = participant[i];
            break;
        }
    }
    
    //participant[-1]값은 completion안에 없다는것이니까 답은 participant에 남은거임
    if(!check) answer = participant[participant.size() - 1];
    
    return answer;
}