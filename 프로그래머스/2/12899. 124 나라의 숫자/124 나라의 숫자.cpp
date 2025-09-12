#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(int n) {
    string answer = "";
    int ax = 0;
    int ay = n;
    while(ay != 0){

        ax = ay % 3; //나머지
        ay /= 3; //몫
        
        if(ax == 0){ //3 6 9
            answer = "4" + answer;
            ay--;
        }
        else if(ax == 1){//1 4 7
            answer = "1" + answer;
        }
        else if(ax == 2){//2 5 8
            answer = "2" + answer;
        }
    }
    
    return answer;
}