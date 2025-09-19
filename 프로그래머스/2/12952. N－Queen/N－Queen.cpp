#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;

int row[12];

bool check(int n){
    //n 보드의 크기
    //i 현재 가로열 위치
    for(int i = 0; i<n; i++){
        if(row[n] == row[i] || abs(row[n] - row[i]) == abs(n - i)){
            return false;
        }
    }
    return true;
}

void nqueen(int n, int depth, int &answer){
    if(depth == n) answer++;
    else{
        for(int i = 0; i<n; i++){
            row[depth] = i;
            if(check(depth)) nqueen(n, depth + 1, answer);
        }
    }
    return;
}

int solution(int n) {
    int answer = 0;
    memset(row, 0, sizeof(row));
    nqueen(n,0, answer);
    
    return answer;
}