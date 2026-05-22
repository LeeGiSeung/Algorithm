#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(int i = 0; i<numbers.size(); i++){
        if(numbers[i] % 2 == 0){
            answer.push_back(numbers[i] + 1);
        }
        else{
            long long check = 1;
            
            while((numbers[i] & check) != 0){
                check <<=1;
            }

            numbers[i] |= check;
            
            //1로킨거의 바로 뒤에있는걸 0으로 바꿈
            //0111
            //1000
            
            numbers[i] ^= (check>>1);
            
            answer.push_back(numbers[i]);
            
        }
    }
    
    return answer;
}