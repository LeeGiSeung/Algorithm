#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> node[20];
int msheep = 0;
vector<int> state;
bool check[20][20][20];

void solve(int cur, int sheep, int wolf){
    if(cur == 0){
        msheep = max(sheep, msheep);
    }
    
    for(int i = 0; i<node[cur].size(); i++){
        int next_node = node[cur][i];
        if(state[next_node] == 0){ //양이면
            if(check[next_node][sheep + 1][wolf] == false){
                check[next_node][sheep + 1][wolf] = true;
                state[next_node] = -1;
                solve(next_node, sheep + 1, wolf);
                state[next_node] = 0;
                check[next_node][sheep + 1][wolf] = false;
            }
        }
        else if(state[next_node] == 1){ //늑대이면
            if(check[next_node][sheep][wolf + 1] == false){
                if(sheep > wolf + 1){
                    check[next_node][sheep][wolf + 1] = true;
                    state[next_node] = -1;
                    solve(next_node, sheep, wolf + 1);
                    state[next_node] = 1;
                    check[next_node][sheep][wolf + 1] = false;
                }
            }
        }
        else{
            if(check[next_node][sheep][wolf] == false){
                check[next_node][sheep][wolf] = true;
                solve(next_node, sheep, wolf);
                check[next_node][sheep][wolf] = false;
            }
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;

    for(int i = 0; i<edges.size(); i++){
        int x = edges[i][0];
        int y = edges[i][1];
        node[x].push_back(y);
        node[y].push_back(x);
    }
    
    state = info;
    state[0] = -1; //최정상 루트
    solve(0,1,0);
    
    answer = msheep;
    return answer ;
}