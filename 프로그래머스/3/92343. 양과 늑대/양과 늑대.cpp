#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Data {
    int Check;  
    int Sheep;  
    int Wolf;   
};

vector<int> node[18];
bool visited[1 << 17]; 

int solution(vector<int> info, vector<vector<int>> edges) {
    int n = info.size();

    for(const auto& edge : edges) {
        node[edge[0]].push_back(edge[1]);
    }
    
    for(int i = 0; i < (1 << n); i++) visited[i] = false;
    
    queue<Data> q;
    
    int startCheck = 1; 
    q.push({startCheck, 1, 0});
    visited[startCheck] = true;
    
    int maxSheep = 1;
    
    while(!q.empty()) {
        Data d = q.front();
        q.pop();
        
        int Check = d.Check;
        int Sheep = d.Sheep;
        int Wolf = d.Wolf;
        
        maxSheep = max(maxSheep, Sheep);
        
        for(int parent = 0; parent < n; parent++){
            if(Check & (1<<parent)){ //지금 Check에서 접근이 되는 애면 접근함
                for(int i = 0; i<node[parent].size(); i++){
                    int nextNode = node[parent][i];
                    
                    //nextNode 간다고했을때 이게 이미 간건지 확인
                    int nextCheck = Check | (1<<nextNode);
                    
                    if(visited[nextCheck]) continue; //이미 방문한거임
                    
                    int nextAnimal = info[nextNode];
                    
                    if(nextAnimal == 0){
                        visited[nextCheck] = true;
                        q.push({nextCheck, Sheep + 1, Wolf});
                    }
                    else{
                        if(Wolf + 1 < Sheep){
                            visited[nextCheck] = true;
                            q.push({nextCheck, Sheep, Wolf + 1});
                        }
                    }
                    
                }
            }
        }
    }
    
    return maxSheep;
}