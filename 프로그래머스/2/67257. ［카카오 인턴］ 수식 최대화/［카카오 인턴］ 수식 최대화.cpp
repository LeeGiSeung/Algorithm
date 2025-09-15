#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<char> check = {'*','+','-'};

long long calcualte(long long a, long long b, char c){
    if(c == '*') return a * b;
    else if(c == '+') return a + b;
    else if(c == '-') return a - b;
}

long long solution(string expression) {
    long long answer = 0;
    
    vector<long long> num;
    vector<char> cal;
    string tmp = "";
    for(int i = 0; i<expression.size(); i++){
        if(isdigit(expression[i])){
            tmp+= expression[i];
        }
        else{
            //부호 들어온거임
            num.push_back(stoll(tmp));
            cal.push_back(expression[i]);
            tmp = "";
        }
    }
    num.push_back(stoll(tmp));
    
    do{
        vector<long long> tmpnum = num;
        vector<char> tmpcal = cal;
        for(int i = 0; i<3; i++){
            for(int j = 0; j<tmpcal.size();){ //cal이 모든 계산 부호 들어간거임
                if(check[i] == tmpcal[j]){
                    //* 랑 * 가 이ㅏㅆ으면
                    long long cur = calcualte(tmpnum[j], tmpnum[j + 1], tmpcal[j]);
                    tmpnum.erase(tmpnum.begin() + j + 1);
                    tmpnum.erase(tmpnum.begin() + j);
                    
                    tmpcal.erase(tmpcal.begin() + j);
                    
                    tmpnum.insert(tmpnum.begin() + j, cur);
                }
                else j++;
            }
        }
        answer = max(answer, abs(tmpnum[0]));
    }while(next_permutation(check.begin(), check.end()));
    
    return answer;
}