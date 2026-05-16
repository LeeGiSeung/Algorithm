#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solve(const int a, const int b){
    string sa = to_string(a);
    string sb = to_string(b);
    
    return sa + sb > sb + sa; 
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), solve);
    
    if(numbers[0] == 0){
        return "0";
    }
    
    for(int i : numbers){
        answer += to_string(i);
    }
    
    return answer;
}