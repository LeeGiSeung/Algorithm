#include <string>
#include <vector>
#include <set>
using namespace std;

int solve(int n, int c){
    int rt = n;
    
    for(int i = 0; i<c; i++){
        rt = (rt * 10) + n;
    }
    
    return rt;
}

int solution(int N, int number) {
    int answer = 0;
    if(N == number) return 1;
    
    //n은 1~9사이
    vector<set<int>> dp(9);
    
    dp[0].insert(N); //N 1개로 표현할 수 있는 수는 N 밖에 없음 ex) 5 1개로는 5
    
    for(int i = 1; i<8; i++){ //2개 ~ 8개 사용
        // 55, 555, 5555
        int mulint = solve(N, i);
        dp[i].insert(mulint);
        for(int x = 0; x<i; x++){
            for(int y = 0; y <i; y++){
                if(x + y + 1 != i) continue; //x개 사용과 y개 사용을 검사해야함
                
                //사칙 연산 집어넣기
                for(int a : dp[x]){ //x개 쓴거랑 y개 쓴거랑 섞기
                    for(int b : dp[y]){
                        dp[i].insert(a + b);
                        if(a - b > 0){
                            dp[i].insert(a - b);
                        }
                        dp[i].insert(a * b);
                        if(a / b > 0){
                            dp[i].insert(a / b);
                        }
                    }
                }
            }
        }
        if(dp[i].find(number) != dp[i].end()){
            answer = i + 1;
            break;
        }
    }
    
    if(!answer) answer = -1;
    
    return answer;
}