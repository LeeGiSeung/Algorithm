#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    //행렬곱

    //행 x 열

    for (int i = 0; i < arr1.size(); i++) { //i 행
        vector<int> v;
        for (int j = 0; j < arr2[0].size(); j++) { //j 열
            int sum = 0;
            for (int z = 0; z < arr2.size(); z++) { 
                sum += arr1[i][z] * arr2[z][j];
            }
            v.push_back(sum);
        }
        answer.push_back(v);
    }

    return answer;
}

int main() {
    //[[1, 4], [3, 2], [4, 1]]	[[3, 3], [3, 3]]
    vector<vector<int>> a = { {1, 4},{3, 2},{4, 1} };
    vector<vector<int>> b = { {3, 3} ,{3, 3 }};

    solution(a,b);
}