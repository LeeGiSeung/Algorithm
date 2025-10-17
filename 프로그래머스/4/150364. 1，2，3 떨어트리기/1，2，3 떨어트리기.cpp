#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

vector<vector<int>> node;
vector<queue<int>> ronode;
vector<int> target;
vector<int> curtarget;
int findleaf(){
    int curleaf = 1;
    int tmpleaf;
    
    while(!ronode[curleaf].empty()){
        tmpleaf = ronode[curleaf].front();
        ronode[curleaf].pop();
        ronode[curleaf].push(tmpleaf);
        curleaf = tmpleaf;
    }
    
    return curleaf;
}

int canfindleaf(){
    int returnInt=0;
    for (int i=0; i<curtarget.size(); i++)
    {
        if (curtarget[i]*3<target[i])
        {
            returnInt=1;
        }
        if (curtarget[i]*1 > target[i])
        {
            returnInt=2;
            return returnInt;
        }
    }
    return returnInt;
}

vector<int> solution(vector<vector<int>> edges, vector<int> _target) {
    vector<int> answer_list;
    
    node = vector<vector<int>>(_target.size() + 1);
    ronode = vector<queue<int>>(_target.size() + 1);
    curtarget = vector<int>(_target.size() + 1, 0);
    target = vector<int>(_target.size() + 1, 0);
    for(int i=1; i<=_target.size(); i++)
        target[i] = _target[i-1];
    
    for(vector<int> v : edges){
        int x = v[0]; int y = v[1];
        node[x].push_back(y);
    }
    
    for(int i = 0; i<node.size(); i++){
        sort(node[i].begin(), node[i].end());
    }
    
    for(int i = 0; i<node.size(); i++){
        for(int j = 0; j<node[i].size(); j++){
            ronode[i].push(node[i][j]);
        }
    }

    int leaf;
    int canleaf;
    
    while(true){
        leaf = findleaf();
        answer_list.push_back(leaf);
        curtarget[leaf]++;
        canleaf = canfindleaf();
        
        if(canleaf == 0){
            break;
        }
        else if(canleaf == 1){
            continue;
        } 
        else if(canleaf == 2){
            return vector<int> (1,-1);
        }
    }
    
    vector<int> answer;
    for (int i=0; i<answer_list.size(); i++)
    {
        int leafNum=answer_list[i];
        curtarget[leafNum]-=1;
        if (curtarget[leafNum]*3>=target[leafNum]-1)
        {
            answer.push_back(1);
            target[leafNum]-=1;
        }
        else if(curtarget[leafNum]*3>=target[leafNum]-2)
        {
            answer.push_back(2);
            target[leafNum]-=2;
        }
        else
        {
            answer.push_back(3);
            target[leafNum]-=3;
        }
    }
    
    return answer;
}