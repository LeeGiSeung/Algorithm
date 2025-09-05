#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2,0);
    int maxlength = 1e8;
    int cur = 0;
    cur = sequence[0];
    //합이 k인 부분 수열
    //두 인덱스의 원소와 그 사이의 원소를 모두 포함하는 부분 수열
    //길이가 짧은 수열
    
    int left = 0;
    int right = 0;
    
    while(left <= right && right < sequence.size()){
        if(cur < k){
            right++;
            cur += sequence[right];
        }
        else if(cur > k){
            cur -= sequence[left];
            left++;
        }
        else if(cur == k){ //left ~ right까지 더한게 k와 같으면
            if(maxlength > right - left){
                maxlength = right - left;
                answer[0] = left;
                answer[1] = right;
                cur -= sequence[left];
                left++; 
            }
            else{
                //같은데 maxlength가 작아서 안되는 경우
                right++;
                cur += sequence[right];
            }
        }
        //cout<<cur<<" "<<left<<" "<<right<<endl;
    }
    
    return answer;
}