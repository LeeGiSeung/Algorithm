#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool idx(vector<int> &a, vector<int> &b){
    return a[1] < b[1]; //index기준으로 정렬
}

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    
    
    vector<vector<int>> food;
    int n = food_times.size();

    for(int i = 0; i<n; i++){
        vector<int> v;
        v.push_back(food_times[i]);
        v.push_back(i + 1);
        food.push_back(v);
    }
    
    sort(food.begin(), food.end());
    
    for(int i = food.size() - 1; i>0; i--){
        food[i][0] -= food[i - 1][0]; //1 1 1
    }   
    bool check = false;

    for(int i = 0; i<food.size(); i++){
        long long time = food[i][0] * n; //현재 소요되는 시간
        
        if(time <= k){
            k -= time; //현재 시간 줄임
             //남은 k 줄임
        }
        else{
            //time이 k 보다 크다는건 더이상 줄일 수 없다는 거임
            //i 이전 값들은 k에서 모두 제거함 i 이후 값들 중에 food에서 찾으면됨
            sort(food.begin() + i, food.end(), idx); //food_times기준으로 정렬된걸 idx 기준으로 재정렬
            answer = food[k % n + i][1];
            check = true;
            break;
        }
        n--;
    }
    if(!check) return -1;
    return answer;
}