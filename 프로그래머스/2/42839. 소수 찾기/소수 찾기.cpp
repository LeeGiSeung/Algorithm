#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

vector<bool> check(9999999, true);
vector<bool> visit(9999999, false);
int answer = 0;
//numbers 주어진 숫자
//CurNumber 지금 조합한 숫자
//CurCheck 지금 선택한 숫자
void solve(string numbers, string CurNumber, vector<bool> CurCheck){
    if(CurNumber != ""){
       if(check[stoi(CurNumber)] && !visit[stoi(CurNumber)]){
            visit[stoi(CurNumber)] = true;
            answer++;
            cout<<stoi(CurNumber)<<endl;
        } 
    }
    //check는 소수 모아둔거임
    //check에서 선택된건 소수니까 answer++;
    for(int i = 0; i<numbers.size(); i++){
        if(CurCheck[i]) continue;
        CurCheck[i] = true;
        solve(numbers, CurNumber + numbers[i], CurCheck);
        CurCheck[i] = false;
    }
}

int solution(string numbers) {
    
    answer = 0;
    
    vector<int> number;    

    check[0] = false;
    check[1] = false;//0,1은 소수아님
    
    for(int i = 0; i<numbers.size(); i++){
        number.push_back(numbers[i] - '0');
    }
    
    sort(number.begin(), number.end());
    
    int n = 0;
    
    for(int i = numbers.size() - 1; i>= 0; i--){
        n += number[i] * pow(10, i);
    }

    for(int i = 2; i * i <= n; i++){
        if(check[i] == true){
            for(int j = i * i; j<=n; j+=i){
                check[j] = false; 
            }
        }
    }
    
    //이제 numbers에 있는 문자열을 섞어서 숫자로 만들고 이게 소수인지 판별하면됨
    
    vector<bool> CurCheck(numbers.size(), false);
    string curnumber;
    solve(numbers, curnumber, CurCheck);
    
    return answer;
}