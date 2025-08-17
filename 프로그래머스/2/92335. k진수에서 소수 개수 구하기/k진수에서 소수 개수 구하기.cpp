#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <cmath>
using namespace std;
int answer = 0;
string jin = "0123456789ABCDEF";

string trans(int n, int k){
    string s = "";
    
    while(n > 0){
        s.push_back(jin[n % k]);
        n /= k;
    }
    
    reverse(s.begin(), s.end());
    
    return s;
}

bool find_answer(string& s) {
    if(s == "") return false;
    long long num = stol(s);
    if(num < 2) return false;
    for(int i=2; i<=sqrt(num); ++i)
        if(num % i == 0) return false;
    return true;
}

int solution(int n, int k) {
    
    string cur = "";
    //위 조건에 맞는 소수
    //0은 소수 아님
    
    cur = trans(n,k);
    //cout<<cur<<endl;
    //0P0처럼 소수 양쪽에 0이 있는 경우 *도중에 있는지 검사
    //P0처럼 소수 오른쪽에만 0이 있고 왼쪽에는 아무것도 없는 경우 //마지막에 있는지 검사
    //0P처럼 소수 왼쪽에만 0이 있고 오른쪽에는 아무것도 없는 경우 //처음에 있는지 검사
    //P처럼 소수 양쪽에 아무것도 없는 경우 //소수만 있는지 검사
    string check = "";
    for(int i = 0; i<cur.size(); i++){
        
        if(cur[i] == '0'){
            if(find_answer(check))
            {
                cout<<check<<endl;
                answer++;
            }
            check = "";
        }

        else{
            check += cur[i];
        } 
 
    }
    
    //마지막에 cur 한번 더 검사
    if(find_answer(check)) answer++;
    
    return answer;
}