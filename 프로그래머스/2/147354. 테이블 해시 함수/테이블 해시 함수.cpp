#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int scol;
int srow_begin;
int srow_end;
bool st(vector<int> &a, vector<int> &b){
    if(a[scol] != b[scol]) return a[scol] < b[scol];
    else{
        //이러면 기본키로 비교
        return a[0] > b[0];
    }
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    scol = col - 1;
    // 첫 번째 컬럼은 기본키
    // 테이블의 튜플을 col번째 컬럼의 값을 기준으로 오름차순 정렬
    // 열은 컬럼을 나타내고, 행은 튜플
    
    //테이블의 데이터 data와 해시 함수에 대한 입력 col, row_begin, row_end
    
    //1. col번째 열을 중심으로 data를 정렬
    //  a. 만약 col 값이 같으면 기본키(0번째 열)을 기준으로 내림차순
    sort(data.begin(), data.end(), st);
    
    //2. row_begin ~ row_begin 값에 기본키를 포함한 행을 나누값을 모두 더한걸 answer에 더함
    for(int i = row_begin; i<= row_end; i++){
        int sum = 0;
        for(int j = 0; j<data[i - 1].size(); j++){
            sum += data[i - 1][j] % i;
        }
        answer = answer ^ sum;
    }
    
    
    return answer;
}