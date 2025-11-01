#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<vector<int>> diceA;
vector<vector<int>> diceB;
vector<int> suma;
vector<int> sumb;

int dicenum = 0;


void makedice(int index, int half, vector<int> a, vector<int> b, vector<vector<int>> &dice){
    if(a.size() == half && b.size() == half){
        //반반 주사위 나누었으면
        diceA.push_back(a);
        diceB.push_back(b);
        return;
    }
    
    if(a.size() == half){
        b.push_back(index);
        makedice(index + 1, half, a, b, dice);
    }
    else if(b.size() == half){
        a.push_back(index);
        makedice(index + 1, half, a, b, dice);
    }
    else{
        a.push_back(index);
        makedice(index + 1, half, a, b, dice);
        a.pop_back();
        
        b.push_back(index);
        makedice(index + 1, half, a, b, dice);
        b.pop_back();
    }
    
}

void cal(int count, int sum ,vector<int>& list, vector<vector<int>>& dice){
    //계산에 필요한거
    //현재 넣은 주사위 갯수, 원본 dice,
    if(count == 0){
        if(dicenum == 0){
            suma.push_back(sum);
        }
        else{
            sumb.push_back(sum);
        }
        return;
    }
    
    for(int i = 0; i<dice[list[count-1]].size(); i++){
        cal(count - 1, sum + dice[list[count-1]][i], list, dice);
    }
    
}

vector<int> dicecom(vector<vector<int>>& dice){
    //diceA
    //diceB
    //두개에 있는걸 서로 꺼내서 계산해야함
    vector<int> win;
    int maxwin = 0;
    for(int i = 0; i<diceA.size(); i++){
        int wincount = 0;
        dicenum = 0;
        cal(diceA[i].size(), 0, diceA[i], dice);
        
        dicenum = 1;
        cal(diceB[i].size(), 0, diceB[i], dice);
        
        for(int j = 0; j<suma.size(); j++){
            for(int z = 0; z<sumb.size(); z++){
                if(suma[j] > sumb[z]){
                    wincount++;
                }
            }
        }
        
        if(wincount > maxwin){
            maxwin = wincount; //새로운 승률 갱신
            win = diceA[i]; //지금 주사위 조합으로 갱신
            sort(win.begin(), win.end()); //오름차순으로 1차원 정수 배열
        }
        suma.clear();
        sumb.clear();
    }
    return win; //최종 승리 주사위 return;
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    vector<int> a,b;
    //dice를 n/2개로 나눌 수 있는 경우의 수 저장
    int half = dice.size() / 2;
    
    makedice(0, half, a, b, dice);
    
    answer = dicecom(dice);
    
    for(int i = 0; i<answer.size(); i++){
        answer[i] += 1;
    }
    
    return answer;
}