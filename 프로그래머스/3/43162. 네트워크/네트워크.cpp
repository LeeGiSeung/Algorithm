#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
vector<int> node(201,0);

int find_parent(int x){
    if(x == node[x]) return x;
    else return find_parent(node[x]);
}

void link_node(int x, int y){
    int tx = find_parent(x);
    int ty = find_parent(y);
    if(tx <= ty){
        node[ty] = tx;
    }
    else{
        node[tx] = ty;
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for(int i = 0; i<n; i++){
        node[i] = i;
    }
    
    for(int i = 0; i<computers.size(); i++){
        for(int j = 0; j<computers[i].size(); j++){
            if(computers[i][j] == 1){
                link_node(i,j); //i와 j 연결
            }
        }
    }
    
    set<int> s;
    
    for(int i = 0; i<n; i++){
        s.insert(find_parent(i));
    }
    
    answer = s.size();
    
    return answer;
}