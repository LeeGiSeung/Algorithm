#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
int answer = 0;
struct Data{
    char from;
    char to;
    char sign; 
    int dist;
};

char kakao[8] = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};

void solve(vector<Data>& v, vector<char> &friends, int depth, vector<bool> &check){
    if(depth == 8){
        
        bool ch = true;
        
        for(int i = 0; i<v.size(); i++){
            char from = v[i].from;
            char to = v[i].to;
            char sign = v[i].sign; 
            int dist = v[i].dist;
            
            int from_index = distance(friends.begin(), find(friends.begin(), friends.end(), from));
            int to_index = distance(friends.begin(), find(friends.begin(), friends.end(), to));
            int curdist = abs(from_index - to_index) - 1;
            
            //5 2 
            //from_index 가 3 to_index가 2 서로 는 1이지만 이건 바로여피니까 1임
            //dist = 0
            if(sign == '>'){
                if(curdist <= dist) ch = false;
            }
            else if(sign == '='){
                if(curdist != dist) ch = false;
            }
            else if(sign == '<'){
                if(curdist >= dist) ch = false;
            }
            
            if(!ch) break;   
        }
        
        if(ch) answer++;
    }
    else{
        for(int i = 0; i<8; i++){
            if(check[i]) continue;
            check[i] = true;
            friends.push_back(kakao[i]);
            solve(v,friends,depth + 1, check);
            friends.pop_back();
            check[i] = false;
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    answer = 0;
    vector<Data> v;
    vector<char> friends;
    vector<bool> check(8, false);

    int depth = 0; 
    // 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
    // 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
    // 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
    // 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
    // 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
    // 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
    
    //네오는 프로도와 나란히 서기를 원했고
    //라이언은 튜브에게서 적어도 세 칸 이상 떨어져서 서기를 원했다
    
    //조건에 제시되는 간격을 의미한다. 이때 간격은 두 프렌즈 사이에 있는 다른 프렌즈의 수
    
    //간격이 2 이하라는건 0 1 2
    for(int i = 0; i<data.size(); i++){
        string s = data[i];
        
        char from = s[0];
        char to = s[2];
        char sign = s[3];
        int dist = s[4] - '0';

        v.push_back({from, to, sign, dist});
    }
    solve(v,friends,depth, check);
    
    return answer;
}