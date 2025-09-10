#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int gcd(int a, int b){
    while(b != 0){
        int ax = a % b;
        a = b;
        b = ax;
    }
    return a;
}

int solve(vector<int> &a){
    int result = a[0];
    for(int i = 1; i < a.size(); i++){
        result = gcd(result, a[i]);
    }
    return result;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    sort(arrayA.begin(), arrayA.end());
    sort(arrayB.begin(), arrayB.end());
    //가장 큰 양의 정수 a 꼭 카드랑 같은 숫자일 필요는 없음자일 필요는 없음
    int a = solve(arrayA);
    int b = solve(arrayB);
    
    if(a != 0){
        bool ch = false;
        for(int i = 0; i<arrayB.size(); i++){
            if(arrayB[i] % a == 0){
                ch = true;
                break;
            }
        }
        if(!ch){
            answer = max(answer, a);
        }
    }
    if(b != 0){
        bool ch = false;
        for(int i = 0; i<arrayA.size(); i++){
            if(arrayA[i] % b == 0){
                ch = true;
                break;
            }
        }
        if(!ch){
            answer = max(answer, b);
        }
    }
    
    return answer;
}