#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
int answer = 0;

vector<vector<int>> node(300001);
vector<int> sales(300001);
vector<vector<int>> dp;

//현재 문제점 1 9 7 비교에서 이미 14가 현재 방에서 최소 값이라는게 밝혀짐
//근데 14 + 17해서 얻은 31보다 19가 작은건 맞지만 이 19는 9를 포함하고잇지않아서 안됨

void dfs(int v){
   dp[v][1]=sales[v];//일단 해당 노드의 방문 시 값으로 초기화

    if(node[v].empty())
        return;

    int minGap=1e9;  //충분히 큰 값. 모든 자식이 미참여했을 때, 그 중 최소가 되는 양수로 정해짐.
    for(auto child : node[v])
    {
        //자식의 정보가 필요하므로 먼저 해당 자식에 대해 재귀 호출
        dfs(child);  

        //자식에 대해 (참여-미참여)의 최소값(0 이상)으로 업데이트
        minGap=min(minGap,max(dp[child][1]-dp[child][0],0));  

        //일단 최소 비용으로 둘 다 업데이트
        dp[v][0]+=min(dp[child][0],dp[child][1]);  
        dp[v][1]+=min(dp[child][0],dp[child][1]);        
    }

    //이제, 팀장 v가 미참여할 시, 팀원 모두도 미참여한 경우를 배제해야 함.
    //minGap==0 이라면 어차피 자식중에 '참여'한 경우가 더해졌을 것이니 볼 필요 없고,
    //모든 자식이 미참여했던 경우(minGap>0)을 dp[v][0]에 추가로 더해줌.
    dp[v][0]+=minGap;
}

int solution(vector<int> isales, vector<vector<int>> links) {
    
    int n = isales.size();
    dp.assign(n + 1, vector<int>(2, 0));
    for(int i = 0; i < n; i++)
        sales[i + 1] = isales[i];
    
    for(auto &v : links)
        node[v[0]].push_back(v[1]);
    
    dfs(1); // 루트 노드
    return min(dp[1][0], dp[1][1]); // 최소 비용 반환
}