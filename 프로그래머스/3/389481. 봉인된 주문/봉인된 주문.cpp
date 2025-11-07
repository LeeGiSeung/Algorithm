#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

string solution(long long n, vector<string> bans) {
    string answer = "";
    vector<long long> lst;
    for(int i = 0; i<bans.size(); i++){
        long long cur = 0;
        for(int j = 0; j<bans[i].size(); j++){
            //각 ban을 n이랑 똑같이 26진수 + 1 long long 형식으로 바꿔야함
            long long k = bans[i][j] - 'a' + 1;
            long long mux = bans[i].size() - 1 - j;
            cur += (k * pow(26,mux));
        }
        lst.push_back(cur);
    }
    
    sort(lst.begin(), lst.end());
    
    for(int i = 0; i<lst.size(); i++){
        if(n >= lst[i]) n++;
        else break;
    }
    while(n){
        //이 n을 알파벳으로 변형함
        long long cur = n % 26 - 1;
        if(cur < 0){ //위에서 1을 뺀건 n이 a가 0이 아니라 1인 형태여서인데
            //여기서 0미만이 나왔다는건 z라는 의미임
            cur = 25; 
            n-=26;
        }
        answer += cur + 'a';
        n /= 26;
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}