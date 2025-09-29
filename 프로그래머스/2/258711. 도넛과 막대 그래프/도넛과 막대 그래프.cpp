#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n = 1000001;
vector<int> out(n, 0);
vector<int> in(n, 0);

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer(4);
    
    for(int i = 0; i<edges.size(); i++){
        int s = edges[i][0];
        int e = edges[i][1];
        out[s]++;
        in[e]++;
    }
    //생성한 정점의 번호, 도넛 모양 그래프의 수, 막대 모양 그래프의 수, 8자 모양 그래프의 수
    for(int i = 1; i<n; i++){
        //정점 노드는 들어오는거 없이 나가는거만 있음
        if(in[i] == 0 && out[i] >= 2) answer[0] = i; //정점 노드
        //막대 노드 들어오는 것만 있고 나가는건 없음
        if(in[i] > 0 && out[i] == 0) answer[2]++;
        //8자 노드 나가고 들어노는게 2개 씩 이여야함 사이즈가 커지는건 8자노드 위아래 덩어리의 크기가 커지는거임
        //들어오고 나가는건 무조건 2개씩
        if(in[i] >= 2 && out[i] == 2) answer[3]++;
    }
    
    answer[1] = out[answer[0]] - answer[2] - answer[3];
    
    return answer;
}