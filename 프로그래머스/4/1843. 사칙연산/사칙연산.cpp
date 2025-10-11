#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;

vector<string> sign;
vector<int> number;

int solution(vector<string> arr)
{
    int answer = -1;
    
    for(int i = 0; i<arr.size(); i++){
        if(i % 2 == 0) number.push_back(stoi(arr[i]));
        else sign.push_back(arr[i]);
    }
    int n = number.size();
    int maxdp[number.size()][number.size()];
    int mindp[number.size()][number.size()];
    
    for(int step = 0; step<n; step++){
        for(int i = 0; i<n - step; i++){
            int j = i + step;
            if(step == 0){
                maxdp[i][j] = number[i];
                mindp[i][j] = number[i];
            }
            else{
                maxdp[i][j] = -1e8;
                mindp[i][j] = 1e8;
                for(int k = i; k<j; k++){
                    if(sign[k] == "+") {
                        //max = max + max
                        maxdp[i][j] = max(maxdp[i][j], maxdp[i][k] + maxdp[k+1][j]);
                        //min = min + min
                        mindp[i][j] = min(mindp[i][j], mindp[i][k] + mindp[k+1][j]);
                    }
                    else {
                        //max = max - min
                        maxdp[i][j] = max(maxdp[i][j], maxdp[i][k] - mindp[k+1][j]);
                        //min = min - max
                        mindp[i][j] = min(mindp[i][j], mindp[i][k] - maxdp[k+1][j]);                        
                    }
                }
            }
        }
    }
    answer = maxdp[0][n-1];
    return answer;
}