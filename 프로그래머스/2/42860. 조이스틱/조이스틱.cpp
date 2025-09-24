#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string name) {
    int answer = 0;
    
    int n = name.size();
    
    for(int i = 0; i<n; i++){
        answer += min(name[i] - 'A', 'Z' - name[i] + 1);
    }
    
    int move = n - 1; //스틱은 n-1번 움직임
    
    for(int i = 0; i<n; i++){
        int next = i + 1;
        while(name[next] == 'A' && next < n) next++;
        move = min(move, i + n - next + min(i, n-next));
    }
    answer += move;
    
    return answer;
}