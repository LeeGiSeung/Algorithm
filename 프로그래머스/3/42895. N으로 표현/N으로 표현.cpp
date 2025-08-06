#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

int solution(int N, int number) {
    int answer = -1;
    set<int> s[8];
    int num = 0;
    for(int i = 0; i<8; i++){
        num = num * 10 + N; //5 55 555
        s[i].insert(num);
        //cout<<num<<endl;
    }
    
    for(int i = 1; i<8; i++){
        for(int j = 0; j<i; j++){
            for(int a : s[j]){
                 for(int b : s[i-j-1]){
                    s[i].insert(a+b);
                    s[i].insert(a-b);
                    s[i].insert(a*b);
                    if(b != 0)
                        s[i].insert(a/b);
                }
            }
        }
    }
    
    for(int i = 0; i < 8; ++i){
        if(s[i].find(number) != s[i].end()){
            answer = i + 1;
            break;
        }  
    }


    //N과 사칙연산만 사용해서 표현 할 수 있는 방법 중 N 사용횟수의 최솟값을 return 하도록 
    
    return answer;
}