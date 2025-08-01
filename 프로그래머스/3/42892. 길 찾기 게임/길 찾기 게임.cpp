#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int n;
struct Node{
    Node* left;
    Node* right;
    int num;
    int x;
    Node(Node* left, Node* right, int num, int x):left(left), right(right), num(num), x(x){}
};

bool solve(const vector<int> &a, const vector<int> &b){
    if(a[1] != b[1]) return a[1] > b[1];
    return a[0] < b[0];
    
}

void find_node(Node* top, Node* cur){
    if(cur->x < top->x){ //left 가야함
        if(top->left == nullptr){
            top->left = cur; //비어있으면 그냥 넣고
        }
        else{
            //안비어있으면 더 들어감
            find_node(top->left, cur);
        }
    }
    if(cur->x > top->x){ //left 가야함
        if(top->right == nullptr){
            top->right = cur; //비어있으면 그냥 넣고
        }
        else{
            //안비어있으면 더 들어감
            find_node(top->right, cur);
        }
    }
}

void find_pre(Node* top, vector<int> &pre){
    if(pre.size() == n) return;
    
    pre.push_back(top->num);
    if(top->left != nullptr){
        find_pre(top->left, pre);
    }
    
    if(top->right != nullptr){
        find_pre(top->right, pre);
    }
}

void find_pro(Node* top, vector<int> &pro){
    if(pro.size() == n) return;
    
    if(top->left != nullptr){
        find_pro(top->left, pro);
    }
    
    if(top->right != nullptr){
        find_pro(top->right, pro);
    }
    pro.push_back(top->num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<Node*> nodelist;
    n = nodeinfo.size();
    //nodeinfo는 이진노드의 좌표 y값이 작을수록 상위 노드임
    
    
    for(int i = 0; i<n; i++){
        nodeinfo[i].push_back(i+1);
    }
    //정렬하기전에 num 넣어야함
    sort(nodeinfo.begin(), nodeinfo.end(), solve);
    
    Node* top = new Node(nullptr, nullptr, nodeinfo[0][2], nodeinfo[0][0]);
    int index = 0;
    
    //for(int i = 0; i<nodeinfo.size(); i++){
        //cout<<nodeinfo[i][0]<<" "<<nodeinfo[i][1]<<endl;
    //}
    
    
    for(int i = 1; i<nodeinfo.size(); i++){
        Node* cur = new Node(nullptr, nullptr, nodeinfo[i][2], nodeinfo[i][0]);
        find_node(top, cur);
    }
    vector<int> pre;
    vector<int> pro;
    find_pre(top, pre);
    find_pro(top, pro);
    answer.push_back(pre);
    answer.push_back(pro);
    return answer;
}