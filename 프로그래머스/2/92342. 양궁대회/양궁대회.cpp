#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool st(vector<int> &a, vector<int> &b){
    for(int i = a.size() - 1; i >= 0; i--){
        if(a[i] != b[i]) return a[i] > b[i];
    }
    return false;
}
vector<vector<int>> answer_list;
int score[11] = {10,9,8,7,6,5,4,3,2,1,0};
int max_score = 0;
int w;
void solve(vector<int> &apeach, vector<int> &lion, int ascore, int lscore, int index ,int n){
    //n 내가 현재 들고있는 화살 수
    
    if(apeach.size() == lion.size()){

        if(lscore > ascore){
                    if(lscore - ascore > max_score){ //만약 새롭게 스코어 갱신되면 answer_list초기화
            max_score = lscore - ascore;
            answer_list.clear();
            answer_list.push_back(lion);
        }
        else if(lscore - ascore == max_score){
            answer_list.push_back(lion);
        }
        }

        
        return;
    }
    else{
        for(int i = index; i<apeach.size(); i++){
            //무조건 화살은 일단 다쓰는쪽으로
            if(n - apeach[i] > 0){
                lion.push_back(apeach[i] + 1);
                solve(apeach, lion, ascore, lscore + score[i], i + 1, n - apeach[i] - 1);
                lion.pop_back();
            }
            if(lion.size() == 10 && n > 0){
                lion.push_back(n);
                solve(apeach, lion, ascore, lscore, i + 1, n - n);
                lion.pop_back();
            }
            else{
                lion.push_back(0);
                if(apeach[i] > 0) 
                    solve(apeach, lion, ascore + score[i], lscore, i + 1, n);
                else 
                    solve(apeach, lion, ascore, lscore, i + 1, n);
                lion.pop_back();
            }
        }
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    vector<int> lion;
    int w = n;
    solve(info, lion, 0, 0, 0 ,n);
    if(answer_list.size() == 0){
        answer.push_back(-1);
    }
    else{
        sort(answer_list.begin(), answer_list.end(), st);
        answer = answer_list[0];
    }
    // 한 선수의 연속 우승보다는 다양한 선수들이 양궁대회에서 우승하기를 원합니다.
    
    //어피치가 a발을 맞혔고 라이언이 b발을 맞혔을 경우
    //더 많은 화살을 k점에 맞힌 선수가 k 점을 가져갑니다.
    //a = b일 경우는 어피치가 k점을 가져갑니다.
    
    //라이언은 어피치를 가장 큰 점수 차이로 이기기 위해서 n발의 화살을 어떤 과녁 점수에 맞혀야 하는지를 구하려고 합니다.
    
    //만약, 라이언이 우승할 수 없는 경우(무조건 지거나 비기는 경우)는 [-1]을 return
    
    //#######################
    //라이언이 어피치를 이길 수 있는 경우는 어피치보다 많은 화살을 맞췄을때 밖에없음
    //라이언 > 어피치 
    //어피치 점수는 미리 계산해놓는게 아니라 라이언구하면서 동시에 구해야함
    
    //########################
    
    
    
    //라이언이 가장 큰 점수 차이로 우승할 수 있는 방법이 여러 가지 일 경우, 가장 낮은 점수를 더 많이 맞힌 경우를 return 해주세요.
    return answer;
}