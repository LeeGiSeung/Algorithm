#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;


vector<vector<int>> node(101);
vector<bool> wirecheck(101, false);

int solve(vector<vector<int>> wires, int x){
    vector<bool> check(101, false);
    
    int answer = 0;
    
    queue<int> q;
    q.push(x);
    check[x] = true;
    while(!q.empty()){
        int qt = q.front();
        q.pop();
        
        answer++;
        
        for(int i = 0; i<node[qt].size(); i++){
            int next_node = node[qt][i]; //다음 노드
            if(check[next_node]) continue; //이미 방문한건 넘어감
            if(wirecheck[qt] && wirecheck[next_node]) continue; //끊은 노드면 가면 안됨
            
            check[next_node] = true;
            
            q.push(next_node);
        }
    }
    
    
    return answer;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 1e9;
    
    //n = 전체 송전탑 갯수
    int halfn = n/2;
    int mincount = 1e9;
    //트리 생성
    for(int i = 0; i<wires.size(); i++){
        node[wires[i][0]].push_back(wires[i][1]);
        node[wires[i][1]].push_back(wires[i][0]);
    }
    
    cout<<halfn<<endl;
    
    for(int i = 0; i<wires.size(); i++){ //해당 전선과 연결된 전선 1개를 끊음
        int x = wires[i][0];
        int y = wires[i][1];
        
        wirecheck[x] = true;//두 라인 방문으로 
        wirecheck[y] = true;
        //현재 줄을 끊고
        int count = solve(wires, x);
        
        //4
        
        //halfn과의 차이가 0에 가까울 수록
        
        if(count != n){ //n하고 count값이 같으면 전봇대가 나뉘어 진게 아님
            
            int checkmin = abs((n - count) - count);
            
            
            
            if(checkmin < mincount){
                //cout<<x<<" "<<y<<" 끊었을때 반환 수 : "<<checkmin<<" 자른 갯수 : "<<count<<endl;
                
                mincount = checkmin;
                answer = checkmin;
            }
            
        }
        
        wirecheck[x] = false;//두 라인 방문으로 
        wirecheck[y] = false;
    }
    
    //송전탑 개수의 차이값을 return 하도록 
    return answer;
}