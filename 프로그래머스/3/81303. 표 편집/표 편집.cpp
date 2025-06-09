#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;

struct Node{
    int idx;
    Node* next;
    Node* prev;
    Node(int _idx, Node* _prev, Node* _next) : idx(_idx), next(_next), prev(_prev) {} //생성자
};

string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'O');
    
    Node* cur = new Node(0, NULL,NULL); //0번째 노드 생성
    Node* select = cur;
    
    stack<Node*> st;
    
    for(int i = 1; i<n; i++){
        cur->next = new Node(i, cur, NULL);
        cur = cur->next;
    }
    
    for(int i = 0; i<k; i++){
        select = select->next;
    }
    
    for(int i = 0; i<cmd.size(); i++){
        string c = cmd[i];
        if(c == "C"){
            st.push(select);
            
            if(select->prev != NULL) //다음이 비어있지 않으면
            {
                select->prev->next = select->next;
            }
            
            if(select->next != NULL){
                select->next->prev = select->prev;
            }
            
            if(select->next == NULL){
                select = select->prev;
            }
            else{ //다음 노선이 안비어있으면 그냥 다음 노선 가면됨
                select = select->next;
            }
            
        }
        else if(c == "Z"){ //가장 최근에 삭제된 행 복구
            Node* rep = st.top();
            st.pop();
            
            if(rep->prev != NULL){
                rep->prev->next = rep;
            }
            
            if(rep->next != NULL){
                rep->next->prev = rep;
            } 
        }
        else{
            int count = stoi(cmd[i].substr(2));
            
            if(c[0] == 'U'){
                for(int i = 0; i<count; i++){
                    select = select->prev;
                }
            }
            else{
                for(int i = 0; i<count; i++){
                    select = select->next;
                }
            }
        }
    }
    
    while(!st.empty()){
        answer[st.top()->idx] = 'X';
        st.pop();
    }
    
    return answer;
}