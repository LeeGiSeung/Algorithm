#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    //0 도난, 1 옷 있음, 2 여벌 있음
    vector<int> check(n + 1, 0);
    
    for(int i = 1; i<=n; i++){
        check[i] = 1;
    }
    
    //여벌의 체육복을 가져온 사람이 도난당했을 수도있으니 먼저 여벌 가져온걸 체크하고 그 뒤에 도난
    for(int i : reserve){
        check[i] = 2;
    }
    
    for(int i : lost){
        if(check[i] == 2){
            check[i] = 1;
        }
        else{
            check[i] = 0;
        }
    }
    
    // 바로 앞번호의 학생이나 바로 뒷번호의 학생에게만 체육복을 빌려줄 수 있습니다
    // 최대한 많은 학생이 체육수업을 들어야 합니다.
    
    //여벌 체육복을 가져온 학생이 체육복을 도난당했을 수 있습니다. 이때 이 학생은 체육복을 하나만 도난당했다고 가정하며, 
    //남은 체육복이 하나이기에 다른 학생에게는 체육복을 빌려줄 수 없습니다.
    
    //앞에놈이 뒷놈한테 주는게 맞음
    //그런데 뒷놈이 앞에놈 검사했는데 없으면 
    
    for(int i = 1; i<=n; i++){
        
        if(check[i] == 0) continue;
        
        if(check[i] == 1){ //그냥 옷만 있으면 빌려줄 여력 없음
            answer++;
            continue;
        }
        else if(check[i] == 2){
            answer++;
        }
        
        if(i == 1){ //무조건 뒷놈만 검사함
            if(check[i + 1] == 0){ //
                check[i + 1] = 1;
                check[0] = 1;
                continue;
            }
        }
        else{
            if(check[i - 1] == 0){
                check[i] = 1; //지금 옷입은거로 바꾸고
                check[i - 1] = 1;
                answer++; //이전껀 이미 반복문 지나서 못바꾸기 때문에 여기서 답 증가
                continue;
            }
            else if(i + 1 <= n){
                if(check[i + 1] == 0){
                    check[i + 1] = 1;
                    check[i] = 1;
                    continue;
                }
            }
        }
    }
    
    //1 2 0 2 0
    //
    
    //X O X O X
    
    for(int i = 1; i<check.size(); i++){
        cout<<check[i]<<" ";
    }
    
    return answer;
}