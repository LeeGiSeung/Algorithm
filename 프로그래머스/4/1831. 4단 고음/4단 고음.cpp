#include <cmath>
int answer = 0;

void solve(int star, int plus, int sum){
    if(plus < (star - 1) * 2){
        return ;
    }
    
    while(sum >= 3){
        if(sum == 3){
            if(plus % 2 == 0){
                if(plus / 2 == star){
                    answer++;
                }
            }
            return;
        }
            int cur = plus/2 - star; //cur = 앞으로 해야할 star 연산 횟수
    if(pow(3, cur) > sum){ //앞으로 남은 3의 제곱 횟수가 남은 n보다 커질 경우 더이상 plus연산을 못함
        return;
    }
    else if(sum % 3 == 0){
        //되면 추가 재귀
        solve(star + 1, plus, sum / 3);
    }
    plus++;
    sum--;
    }

}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n) {
    answer = 0;
    
    solve(1,2,n-2);
    
    return answer;
}