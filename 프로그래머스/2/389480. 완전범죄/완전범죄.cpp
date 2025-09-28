#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int answer = -1;

bool st(vector<int> &a , vector<int> &b){
    if(a[0] - a[1] == b[0] - b[1]){
        //둘이 값이 같으면 비율이 적을걸 내림
        return(a[0] / a[1] > b[0] / b[1]);
    }
    else{
        return a[0] - a[1] > b[0] - b[1];
    }
}

int solution(vector<vector<int>> info, int n, int m) {
    
    sort(info.begin(), info.end(), st);
    
    //a는 최소화
    //a와 b모두 경찰에 들키면 안됨
    
    int asum = 0;
    int bsum = 0;
    for(int i = 0; i<info.size(); i++){
        int a = info[i][0];
        int b = info[i][1];
        //cout<<asum<<" "<<bsum<<endl;
        //b 좀 더 더할 수 있는 상황이면 b 먼저
        if(b + bsum < m){    
            bsum += b;
        }
        else if(a + asum < n){
            asum += a;            
        }
        else return -1;
        
    }
    
    
    return asum;
}