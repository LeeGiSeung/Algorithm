#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>
#include <numeric>

using namespace std;

long long solution(int w,int h) {
    long long answer = 1;

    answer = (long long)w * (long long)h;
    int x = gcd(w,h); //x 최대공약수
    
    answer = answer - ((w / x + h / x) - 1) * x;
    
    return answer;
}