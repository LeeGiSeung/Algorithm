#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

struct Tree{
    Tree *node[26];
    int num = 0;
    
    public:
        Tree(){
            for(int i = 0; i<26; i++) node[i] = NULL;
        }
    
    void insert(const char *c){
        num++;
        if(*c == '\0') return;
        
        int next = *c - 'a';
        if(node[next] == NULL) node[next] = new Tree();

        node[next]->insert(c + 1);
    }
    /*
    int find(string str, int idx, int cnt){
        int index = str[idx] - 'a';
        
        if(idx == str.size() -1 || node[index]->num == 1) return cnt;
        
        return node[idx]->find(str, idx + 1, cnt + 1);
    }
    */
    int find(const string &str, int idx = 0, int cnt = 1){
        int index = str[idx] - 'a';
        if(idx == str.size() -1 || node[index]->num == 1) return cnt;
        return node[index]->find(str, idx + 1, cnt + 1);
    }
    
};

int solution(vector<string> words) {
    int answer = 0;
    map<string, int> m;
    // 순서대로 찾을 때 몇 개의 문자를 입력하면 되는지 계산하는 프로그램을 만들어보자.
    
    sort(words.begin(), words.end());
    Tree *node = new Tree();
    for(string s : words){
        node->insert(s.c_str());
    }
    
    for(string s : words){
        answer += node->find(s, 0, 1);
    }
    return answer;
}