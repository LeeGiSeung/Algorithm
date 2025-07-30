#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

struct Node{
    Node* next;
    Node* back;
    int num;
    Node(Node* next, Node* back, int num) : num(num), back(back), next(next) {}
};

string solution(int n, int k, vector<string> cmd) {
    stack<Node*> st;
    string answer(n,'O');
    
    //Node* next;
    //Node* back;
    //int num;
    
    Node *z = new Node(NULL,NULL,0);
    Node *select = z;
    
    for(int i = 1; i<n; i++){
        z->next = new Node(NULL, z, i); //현재 고른 노드의 다음은 새롭게 만든노드
        z = z->next; //현재 노드를 새롭게 만든노드로 변경
    }
    
    for(int i = 0; i<k; i++){
        select = select->next;
    }
    
    //cmd 명령어가 담긴 cmd
    for(string s : cmd){
        if(s == "C"){
            st.push(select);
            if(select->back != NULL){
                select->back->next = select->next;
            }
            if(select->next != NULL){
                select->next->back = select->back;
            }
            
            if(select->next == NULL){
                select = select->back;
            }
            else{
                select = select->next;
            }
        }
        else if(s == "Z"){
            Node *cur = st.top();
            st.pop();
            if(cur->next != NULL){
                cur->next->back = cur;
            }
            if(cur->back != NULL){
                cur->back->next = cur;
            }
        }
        else{
            int a = stoi(s.substr(2));
            for(int i = 0; i<a; i++){
                if(s[0] == 'U'){
                    select = select->back;
                }
                if(s[0] == 'D'){
                    select = select->next;
                }
            }
        }
    }
    
    while(!st.empty()){
        Node* cur = st.top();
        answer[cur->num] = 'X';
        st.pop();
    }
    
    return answer;
}