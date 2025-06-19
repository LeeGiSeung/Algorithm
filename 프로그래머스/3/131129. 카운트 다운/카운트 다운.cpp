#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int dp[100001][2];

void solve(int target){
    if(dp[target - 60][0] == dp[target - 50][0]){
        dp[target][0] = dp[target - 50][0] + 1;
        dp[target][1] = dp[target - 50][1] + 1;
    }
    else if(dp[target - 60][0] < dp[target - 50][0]){
        dp[target][0] = dp[target-60][0] + 1;
        dp[target][1] = dp[target-60][1];
    }
    else if(dp[target - 60][0] > dp[target - 50][0]){
        dp[target][0] = dp[target-50][0] + 1;
        dp[target][1] = dp[target-50][1] + 1;
    }
}

vector<int> solution(int target) {
    vector<int> answer;
    
    // "싱글"을 맞히면 해당 수만큼 점수를 얻고
    // "더블"을 맞히면 해당 수의 두 배만큼 점수를 얻고
    // "트리플"을 맞히면 해당 수의 세 배만큼 점수를 얻습니다.
    // 가운데에는 "불"과 "아우터 불"이 있는데 "카운트 다운" 게임에서는 구분 없이 50점
    
    // 가장 먼저 0점을 만든 선수가 승리하는데
    // 두 선수가 같은 라운드에 0점을 만들면 두 선수 중 "싱글" 또는 "불"을 더 많이 던진 선수가 승리
    // 이마저도 같으면 선공한 애가 승리
    
    //answer 다트 수와 /싱글 또는 불을 맞춘 횟수
    
    dp[0][0] = 0;
    dp[0][1] = 0;
    
    for(int i = 1; i<=target; i++){
        if(i == 50 || i<= 20){
            dp[i][0] = 1; //다트 1개만 던져도됨
            dp[i][1] = 1; //1~20은 다트판에 1개씩 존재해서 싱글만 맞히면 다 됨 or 50이면 불 한번
        }
        else if(i <= 60 && i % 3 == 0){
            dp[i][0] = 1;
            dp[i][1] = 0;
            //트리플 한번으로 되는거면 1번만 던져도됨
        }
        else if( i <= 40 &&i % 2 == 0){
            dp[i][0] = 1;
            //40이하고 2의 배수이면 더블로 처리가능
        }
        else if(i <= 70 && i> 50){
            dp[i][0] = 2;
            dp[i][1] = 2;
        }
        else if(i <= 70){
            //40이하인데 2와 3의 배수가 아니면 싱글 두개로
            if(i<40){
                dp[i][0] = 2;
                dp[i][1] = 2;
            }
            else if(i>40){
                dp[i][0] = 2;
                dp[i][1] = 1;
            }
        }
        else{ //70이상
            solve(i);
        }
    }
    
    answer.push_back(dp[target][0]);
    answer.push_back(dp[target][1]);
    
    return answer;
}