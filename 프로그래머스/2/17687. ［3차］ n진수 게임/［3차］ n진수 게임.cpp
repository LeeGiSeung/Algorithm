#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <bitset>
using namespace std;

string ans = "0123456789ABCDEF";

string make_str(int num, int n){
    string result = "";
    if(num == 0) return "0";
    
    while(num / n != 0){
        string cur = result;
        result += ans[num % n];
        num /= n;
    }
    string cur = result;
    result += ans[num % n];
    
    reverse(result.begin(), result.end());
    
    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    int lng = t * m; //딱 이정도 정보만 필요함
    string longans = "";
    for(int i = 0; i<lng; i++){
        longans += make_str(i, n);
    }
    int cnt = 0;
    for(int i = p - 1; i<longans.size(); i += m){
        if(cnt >= t) break;
        answer += longans[i];
        cnt++;
    }
    
    return answer;
}