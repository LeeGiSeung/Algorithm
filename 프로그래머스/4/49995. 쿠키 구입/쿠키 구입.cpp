#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> cookie) {
    int answer = 0;
    if(cookie.size() == 1) return answer; //바구니가 1개면 무조건 안됨
    

    for(int i = 0; i<cookie.size() - 1; i++){ //왼쪽 , 오른쪽 나눠야해서 i는 왼쪽 기준임
        //[1,1,2,3] 여기서 기준을 0,1,2,3 나눠서 양쪽을 검사
        int leftidx = i;
        int rightidx = i + 1;
        int left = cookie[leftidx];
        int right = cookie[rightidx];
        
        while(true){
            if(left == right){
                answer = max(answer, left);
                
                bool check = false;
                
                if(rightidx + 1 < cookie.size()){
                    right += cookie[++rightidx];  
                    check = true;
                }
                else if(rightidx - 1 >= 0){
                    left += cookie[--leftidx];  
                    check = true;
                }
                
                if(!check) break;
            }
            else{
                if(left > right){ //left가 더 크면 rightidx를 높혀야함
                    if(rightidx + 1 >= cookie.size()) break;
                right += cookie[++rightidx];  
            }
                if(right > left){ //left가 더 크면 rightidx를 높혀야함
                    if(leftidx - 1 < 0) break;
                    left += cookie[--leftidx];  
                }
            }
            
        }
        
    }
    
    
    return answer;
}