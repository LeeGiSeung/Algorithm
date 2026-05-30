#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<vector<int>> cplus(25,vector<int>(2005, 0));
vector<vector<int>> cminus(25,vector<int>(2005, 0));

vector<vector<bool>> visited_plus(25,vector<bool>(2005, false));
vector<vector<bool>> visited_minus(25,vector<bool>(2005, false));

vector<int> numbers;
int n;
int target;
int answer = 0;

int dfs(int cur, int idx){
if(idx >= n){
        // 타겟 넘버를 만들었다면 1개 발견(1 리턴), 아니면 실패(0 리턴)
        if(cur == target){
            return 1;
        }
        else{
            return 0;
        }
    }
    
    if (cur >= 0) {
        if (visited_plus[idx][cur]) return cplus[idx][cur];
    } else {
        if (visited_minus[idx][-cur]) return cminus[idx][-cur];
    }

    // 현재 숫자를 더했을 때 나오는 정답 개수 + 뺐을 때 나오는 정답 개수
    int ch1 = dfs(cur + numbers[idx], idx + 1);
    int ch2 = dfs(cur - numbers[idx], idx + 1);
    
    int result = ch1 + ch2; // 두 경로에서 나온 모든 정답 수를 합산!

    if (cur >= 0) {
        visited_plus[idx][cur] = true;
        cplus[idx][cur] = result;
    } else {
        visited_minus[idx][-cur] = true;
        cminus[idx][-cur] = result;
    }

    return result;
    
}

int solution(vector<int> _numbers, int _target) {
    answer = 0;
    numbers = _numbers;
    target = _target;
    n = numbers.size();
    // 이 정수들을 순서를 바꾸지 않고
    
    return  dfs(0,0);
}