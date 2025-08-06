#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int dp[100001][2];

void find_dp(int target){
    if(dp[target - 60][0] == dp[target - 50][0]){ //60이전과 50이전의 횟수가 같으면 
        //볼을 던지는게 정답임
        dp[target][0] = dp[target - 50][0] + 1;
        dp[target][1] = max(dp[target-60][1], dp[target-50][1] + 1);
    }
    else if(dp[target - 60][0] < dp[target - 50][0]){
        dp[target][0] = dp[target - 60][0] + 1;
        dp[target][1] = dp[target-60][1];
    }
    else
    {
        dp[target][0] = dp[target - 50][0] + 1;
        dp[target][1] = dp[target-50][1] + 1;
    }
}

vector<int> solution(int target) {
    vector<int> answer(2,0);
    memset(dp,0,sizeof(dp));
    for(int i = 1; i<= target; i++){
        if(i <= 20 || i == 50){ //20이하면 싱글 한번에, 50이면 불 한번에
            dp[i][0] =1;
            dp[i][1] =1;
        }
        else if(i % 2 == 0 && i <= 40){ //2의 배수 40이하면 1 번 던지기
            dp[i][0] =1;
        }
        else if(i % 3 == 0 && i <= 60){ //3의 배수 60이하면 1 번 던지기
            dp[i][0] =1;
        }
        else if(i >= 50 && i <= 70){ //70까지가 볼 + 싱글로 만들 수 있는 최대 수
            dp[i][0] =2;
            dp[i][1] =2;
        }
        else if(i > 20 && i <= 49){ //21~49까지
            if(i > 20 && i <= 40){
                //싱글 2번
                dp[i][0] = 2;
                dp[i][1] = 2;
            }
            else{
                dp[i][0] = 2;
                dp[i][1] = 1;
            }
        }
        else{
            //그 이상 5만, 2만 이런거
            find_dp(i);
        }
    }
    answer[0] = dp[target][0];
    answer[1] = dp[target][1];
    return answer;
}