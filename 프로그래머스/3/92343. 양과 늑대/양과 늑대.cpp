#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

vector<int> info;
vector<vector<int>> node(18, vector<int>());
int maxsheep = 1;

int visited[1<<18];

struct Data{
    int visit;
    int sheep;
    int wolf;
};

void solve(){
    queue<Data> q;
    
    q.push({1,1,0});
    
    while(!q.empty()){
        Data d = q.front();
        q.pop();
        
        int visit = d.visit;
        int sheep = d.sheep;
        int wolf = d.wolf;
        
        maxsheep = max(sheep, maxsheep);
        
        for(int i = 0; i<info.size(); i++){
            if(visit & (1<<i)){ //뻗을 수 있는 노드이면
                for(int j = 0; j<node[i].size(); j++){
                    int next = node[i][j];
                    if(visit & (1<<next)) continue;
                    
                    int next_sheep = sheep + (info[next] == 0);
                    int next_wolf = wolf + (info[next] == 1);
                    int next_visit = visit | (1<<next);
                    
                    if(next_sheep > next_wolf && !visited[next_visit]){
                        visited[next_visit] = true;
                        q.push({next_visit,next_sheep,next_wolf});
                    }
                }
            }
        }
        
    }
    
}

int solution(vector<int> _info, vector<vector<int>> _edges) {
    maxsheep = 1;
    
    for(vector<int> v : _edges){
        node[v[0]].push_back(v[1]);
    }
    info = _info;
    solve();
    
    //같은 양을 들고 같은 노드에 방문을 2번하면 그건 이후에도 바뀔일이 없다는거임
    
    return maxsheep;
}