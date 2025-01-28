#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 체인의 길이를 오름차순으로 정렬한 뒤에, 적은 수의 체인부터 고리로 풀어헤치면서 큰 수의 체인을 연결한다.
int main(){
    int n;
    int cnt = 0;
    vector <int> v;

    cin >> n;

    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    while(1){
        if(v.size() == 1)
            break;
        
        v[v.size() - 2] += v[v.size() - 1];
        v.pop_back();
        cnt++;
        v[0]--;

        if(v[0] == 0){
            for(int i = 0; i < v.size() - 1; i++){
                v[i] = v[i + 1];
            }
            v.pop_back();
        }
    }

    cout << cnt;

}