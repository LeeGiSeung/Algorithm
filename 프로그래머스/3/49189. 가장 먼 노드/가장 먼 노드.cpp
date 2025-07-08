#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

vector<int> v[20001];
bool check[20001];
int answer = 0;
int fall = 1;


int solution(int n, vector<vector<int>> edge) {
    
    for(int i = 0; i<edge.size(); i++){
        int a = edge[i][0];
        int b = edge[i][1];
        
        v[a].push_back(b);
        v[b].push_back(a);
    }
    check[1] = true;
    //1번 노드에서 가장 멀리 떨어진 노드의 갯수
    queue<pair<int,int>> q;
    q.push({1,1});
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if(y == fall){
            answer+=1;
            //cout<<"증가"<<fall<<endl;
        }
        else if(y > fall){
            answer = 1;
            fall = y;
            //cout<<x<<"갱신"<<fall<<endl;
        }
        
        for(int i = 0; i<v[x].size(); i++){
            int next_node = v[x][i];
            
            if(check[next_node]) continue;
            //cout<<next_node<<endl;
            check[next_node] = true;
            q.push({next_node, y+1});
        }
    }
    
    return answer;
}