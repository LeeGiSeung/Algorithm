#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;

    while(n != 0){
        answer += n % 10;
        //cout<<answer<<endl;
        n /= 10;
    }

    return answer;
}