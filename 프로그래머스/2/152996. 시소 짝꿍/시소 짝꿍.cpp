#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    
    //1 : 1(같은거)
    //2 : 3
    //2 : 4
    //3 : 4
    
    map<long long, long long> m;
    for(int i : weights) m[i]++;
    
    for(pair<long long, long long> p : m){
        long long num = p.first;
        long long count = p.second;
        
        if(count > 1){
            answer += count * (count - 1) / 2;
        }
        
        //2 : 3
        if(num * 3 % 2 == 0){
            if(m.find(num * 3 / 2) != m.end()){
                answer += m[num * 3 / 2] * count;
            }
        }
        
        //2 : 4
        if(num * 4 % 2 == 0){
            if(m.find(num * 4 / 2) != m.end()){
                answer += m[num * 4 / 2] * count;
            }
        }
        //3 : 4
        if(num * 4 % 3 == 0){
            if(m.find(num * 4 / 3) != m.end()){
                answer += m[num * 4 / 3] * count;
            }
        }
    }
        
    return answer;
}