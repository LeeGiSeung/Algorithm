#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct Node{
    int x;
    int y;
    int idx;
    Node* left;
    Node* right;
    Node(int _x, int _y, int _idx) : x(_x), y(_y), idx(_idx), left(nullptr), right(nullptr) {}
};

void insert(Node* parent, Node* child){
    if(child->x < parent->x){
        //작으면 왼쪽임
        if(parent->left == nullptr) parent->left = child; //비어있으면 그냥 가고
        else insert(parent->left, child); //안비어있으면 이어서
    }    
    else
    {
        //작으면 왼쪽임
        if(parent->right == nullptr) parent->right = child; //비어있으면 그냥 가고
        else insert(parent->right, child); //안비어있으면 이어서
    }
}

bool solve(const Node* a, const Node* b){
    if(a->y == b->y) return a->x < b->x;
    return a->y > b->y;
}

void find_pre (Node* cur, vector<int> &res){
    //전위
    if(cur == nullptr) return;
    res.push_back(cur->idx);
    find_pre(cur->left, res);
    find_pre(cur->right, res);
}

void find_pro (Node* cur, vector<int> &res){

    if(cur == nullptr) return;
    find_pro(cur->left, res);
    find_pro(cur->right, res);
    res.push_back(cur->idx);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<Node*> nodes;
    
    for(int i = 0; i<nodeinfo.size(); i++){
        nodes.push_back(new Node(nodeinfo[i][0], nodeinfo[i][1], i + 1));
    }
    
    sort(nodes.begin(), nodes.end(), solve);
    
    for(int i = 0; i<nodes.size(); i++){
        cout<<nodes[i]->x<<endl;
    }
    
    Node* root = nodes[0]; //최상위 루트
    
    for(int i = 1; i<nodes.size(); i++){
        insert(root, nodes[i]);
    }
    
    vector<int> pre;
    vector<int> pro;
    find_pre(root, pre);
    find_pro(root, pro);
    
    answer.push_back(pre);
    answer.push_back(pro);
    
    return answer;
}