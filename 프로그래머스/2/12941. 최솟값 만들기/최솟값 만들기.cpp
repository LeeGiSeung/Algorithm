#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(), A.end());

    sort(B.begin(), B.end());
    reverse(B.begin(), B.end());

    //최소값을 나오게 하려면 큰수 x 작은수해줘야함

    for (int i = 0; i < A.size(); i++) {
        answer += A[i] * B[i];
    }

    return answer;
}