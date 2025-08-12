#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;

vector<int> node[300001];
long long answer = 0;

void dfs(vector<long long>& sum, int cur, int par){
    for(int i = 0; i<node[cur].size(); i++){
        if(node[cur][i] != par)
            dfs(sum,node[cur][i],cur);
    }
    
    sum[par] += sum[cur];
    answer += abs(sum[cur]);
    return;
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    vector<long long> sum(a.size(), 0);
    for(int i = 0; i<a.size(); i++){
        sum[i] = a[i];
    }
    for(int i = 0; i<edges.size(); i++){
        node[edges[i][0]].push_back(edges[i][1]);
        node[edges[i][1]].push_back(edges[i][0]);
    }
    dfs(sum,0,0);
    
    if (sum[0] == 0) return answer;
    
    return -1;
}