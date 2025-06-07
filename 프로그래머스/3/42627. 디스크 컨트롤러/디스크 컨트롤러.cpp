#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool solve(const vector<int> &a, const vector<int> &b){
    return a[1] <= b[1];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0;
    int jobs_size = jobs.size();

    sort(jobs.begin(), jobs.end(), solve);
    
    while(!jobs.empty()){
        for(int i = 0; i<jobs.size(); i++){
            if(time >= jobs[i][0]){
                time += jobs[i][1];
                answer += (time - jobs[i][0]);
                cout<<time - jobs[i][0]<<endl;
                jobs.erase(jobs.begin() + i);
                break;
            }
            if(i == jobs.size() - 1) time++;
        }
    }
    
    return answer / jobs_size;
}