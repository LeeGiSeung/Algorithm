#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    
    for(int i = 0; i<phone_book.size() - 1; i++){
        if(phone_book[i].size() > phone_book[i + 1].size()) continue; //앞놈 크기가 더 크면 비교안됨
        bool check = false;
        for(int j = 0; j<min(phone_book[i].size(), phone_book[i + 1].size()); j++){
            if(phone_book[i][j] != phone_book[i + 1][j]){
                check = true;
                continue;
            }
        }
        
        
        if(!check) return false;
    
    }
    
    return answer;
}