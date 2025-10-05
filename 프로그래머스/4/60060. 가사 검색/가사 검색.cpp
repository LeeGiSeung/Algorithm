#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
using namespace std;

struct Node{
    int num = 0; //노드 생성되면 무조건 1은 가지고있어야지
    Node* node[26];
    
    Node(){
        for(int i = 0; i<26; i++){
            node[i] = NULL; //node 초기화
        }
    }
    
    void insert(const char* c){
        if(*c == '\0') return; //마지막이면 return
        
        int next = *c - 'a';
        
        if(node[next] == NULL){
            //현재 *c로 가는게 null이면 아직 가본적 없는거
            node[next] = new Node();
        }
        
        node[next]->num++;
        node[next]->insert(c + 1);
    }
    
    int find(const char* c){
        if(*c == '\0' || *c == '?') return num; //? 이면 더이상 갈 필요없음
        int next = *c - 'a';
        if(node[next] == NULL) return 0;
        return node[next]->find(c + 1);
        
    }
};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    map<int, Node*> m;
    map<int, Node*> rm;
    //각 키워드 별로 매치된 단어가 몇 개인지
    
    //가사에 사용된 모든 단어들이 담긴 배열 words
    //찾고자 하는 키워드가 담긴 배열 queries
    
    for(int i = 0; i<words.size(); i++){

        //    Node *root = new Node();
        int n = words[i].size();
        if(m[n] == NULL) m[n] = new Node();
        if(rm[n] == NULL) rm[n] = new Node();
        
        m[n]->insert(words[i].c_str());
        
        string s = words[i];
        reverse(s.begin(), s.end());
        
        rm[n]->insert(s.c_str());
        rm[n]->num++;
    }
    
    for(int i = 0; i<queries.size(); i++){
        //words가 변환할 수 있는 모든 경웅의 수에 해당하는 ?를 추가한 숫자를 만들어서 map에 넣고 
        //queries에서는 이거 꺼내가야함
        int w = queries[i].size();
        
        if (queries[i][0] == '?') {
            if(rm[w] == NULL) answer.push_back(0);
            else{
                            string s = queries[i];
            reverse(s.begin(), s.end());
            answer.push_back(rm[w]->find(s.c_str()));
            }
            // 물음표가 앞쪽 -> 역방향 탐색

        } else {
            if(m[w] == NULL) answer.push_back(0);
            else{
answer.push_back(m[w]->find(queries[i].c_str()));
            }
            // 물음표가 뒤쪽 -> 정방향 탐색
            
        }
    }
    
    return answer;
}