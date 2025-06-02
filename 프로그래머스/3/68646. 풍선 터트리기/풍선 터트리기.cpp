#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int left[1000001];
int right[1000001];

int solution(vector<int> a) {
    int answer = 0;
    
    //작은 풍선을 터트리는 행위는 딱 1번만 가능하다.
    //원래는 큰 풍선을 터트리는게 맞음
    int min = a[0];
    
    for(int i = 0; i<a.size(); i++){
        if(a[i] < min){
            min = a[i];
        }
        left[i] = min;
    }
    
    min = a[a.size() - 1];
    for(int i = a.size() - 1; i >= 0; i--){
        if(a[i] < min){
            min = a[i];
        }
        right[i] = min;
    }
    
    for(int i = 0; i<a.size(); i++){
        int count = 0;
        if(a[i] > left[i]) count++;
        if(a[i] > right[i]) count++;
        
        if(count < 2){
            answer++;
        }
    }
    
    return answer;
}