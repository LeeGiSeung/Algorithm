#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    //n 사람 수
    //a 플레이어 A
    //b 플레이어 B

    //N	    A	    B	    answer
    //8	    4	    7	    3

    //2 4 8 

    //8안에 있으면 3
    //16안에 있으면 4
    int a_area = a;
    int b_area = b;

    while (a_area != b_area) {
        a_area = a_area / 2 + a_area % 2;
        b_area = b_area / 2 + b_area % 2;
        answer++;
    }

    return answer;
}