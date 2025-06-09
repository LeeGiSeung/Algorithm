#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int dist[202][202];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 1e8;
    
    for(int i = 1; i<= n; i++){
        for(int j = 1; j<=n; j++){
            if(i == j) continue;
            dist[i][j] = 1e8;
        }
    }
    
    for(int i = 0; i<fares.size(); i++){
        int from = fares[i][0];
        int to = fares[i][1];
        int cost = fares[i][2];
        dist[from][to] = cost;
        dist[to][from] = cost;
    }
    
    //중간노드
    //시작
    //끝
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            for(int z = 1; z<=n; z++){
                if(j == z) continue;
                dist[j][z] = min(dist[j][z], dist[j][i] + dist[i][z]);
            }
        }
    }
    
    for(int i = 1; i<=n; i++){
        answer = min(answer, dist[s][i] + dist[i][a] + dist[i][b]);
    }
    
    return answer;
}