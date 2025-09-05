#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

int solution(int storey) {
    int answer = 0;

    while(storey > 0){
        int check = storey % 10; //1의 자리
        storey /= 10;
        
        if(check < 5){
            answer += check; //정직하게 내리면됨
        }
        else if(check > 5){
            storey += 1;
            answer += 10 - check;
        }
        else if(check == 5){
            int a = storey % 10;
            if(a >= 5){
                storey+=1;
            }
            answer += check;
        }
    }
    
    return answer;
}