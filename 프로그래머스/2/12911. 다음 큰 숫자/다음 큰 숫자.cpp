#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    
    int bitcount = __builtin_popcount(n);
    
    while(__builtin_popcount(n+1) != bitcount){
        n++;
    }
    
    return n+1;
}