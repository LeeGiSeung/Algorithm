#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool st(vector<int> &a, vector<int> &b){
    if(a[0] != b[0]) return a[0] > b[0];
    if(a[1] != b[1]) return a[1] > b[1];
    return a[2] > b[2];
}

int pickaxe[3][3] = {{1,1,1},{5,1,1},{25,5,1}};

int solve(int mineral, vector<int> v){
    int sum = 0;
    //cout<<mineral<<endl;
    //v는 list임
    for(int i = 0; i<3; i++){  
        sum += pickaxe[mineral][i] * v[i];
        //cout<<pickaxe[mineral][i]<<" "<<v[i]<<endl;
    }
    //cout<<endl;
    return sum;
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    
    //마인이 작업을 끝내기까지 필요한 최소한의 피로도
    
    //dia, iron, stone
    
    //각 곡괭이는 종류에 상관없이 광물 5개를 캔 후에는 더 이상 사용할 수 없습니다.
    //광물은 주어진 순서대로만 캘 수 있습니다.
    
    //광산에 있는 모든 광물을 캐거나, 더 사용할 곡괭이가 없을 때까지 광물을 캡니다.
    
    //즉, 곡괭이를 하나 선택해서 광물 5개를 연속으로 캐고
    
    //곡괭이로 5개 캘 수 있으니까 5개씩 묶어서 우선순위 정해야함
    int usepickaxe = picks[0] + picks[1] + picks[2];
    vector<vector<int>> list;
    vector<int> lock(3);
    int index = 0;
    int cdx = 0;
    for(int i = 0; i<minerals.size(); i++){
        index++;
        if(minerals[i] == "diamond"){
            lock[0]++;
        }
        else if(minerals[i] == "iron"){
            lock[1]++;
        }
        else if(minerals[i] == "stone"){
            lock[2]++;
        }
        
        if(index == 5){
            list.push_back(lock);
            vector<int> reset(3);
            lock = reset;
            index = 0;
            cdx++;
        }
    }
    
    //3 2 0
    //1 1 1
    
    if(minerals.size() % 5 != 0){
        cdx++;
        list.push_back(lock); //5배수아니면 수동으로 마지막
    } 
    
    if(list.size() > usepickaxe){
        list.resize(usepickaxe);
    }
    
    sort(list.begin(), list.end(), st);
    
    //list 에는 5개씩 묶은 광물이 들어있음
    //picks는 곡괭이들의 갯수
    
    //picks 0~picks.size() 하나씩 꺼내서 list.size() 갯수 계산해야함
    
    int list_index = 0;

    for(int i = 0; i<picks.size(); i++){
        for(int j = 0; j<picks[i]; j++){

            if(list_index >= list.size()){
                return answer; //만약 가지고있는 모둔 광물 썼으면 바로 return
            } 
            answer += solve(i ,list[list_index]);
            list_index++;
        }
    }
    
    return answer;
}