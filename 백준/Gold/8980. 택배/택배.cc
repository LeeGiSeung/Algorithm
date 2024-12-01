#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int N, TRUCK, C;
int CUR_TRUCK_KG;

long long RESULT = 0;
vector<pair<int, int>> v[30];
vector<pair<int, int>> MOVING_TRUCK;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> TRUCK >> C;
    for (int i = 0; i < C; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({ b,c });
    }

    for (int i = 0; i <= N; i++) {
        if (v[i].empty()) {
            continue;
        }
        sort(v[i].begin(), v[i].end());
    }

    //N개의 마을 순방
    for (int i = 1; i <= N; i++) {
        //1. 짐을 내려 놓는다.
        //int CUR_TRUCK_BOX = MOVING_TRUCK.size();
        for (int j = 0; j < MOVING_TRUCK.size(); j++) {
            //만약 현재 마을 일때
            if (MOVING_TRUCK[j].first == i) {
                //현재 박스 무게만듬 트럭이 가벼워짐
                CUR_TRUCK_KG -= MOVING_TRUCK[j].second;
                MOVING_TRUCK.erase(MOVING_TRUCK.begin() + j);
            }
            else if (MOVING_TRUCK[j].second == 0) {
                MOVING_TRUCK.erase(MOVING_TRUCK.begin() + j);
            }
        }
        //2. 짐을 싣는다
        for (int j = 0; j < v[i].size(); j++) {
            //그냥 전체를 실을 수 있는 경우
            if (CUR_TRUCK_KG + v[i][j].second <= TRUCK) {
                MOVING_TRUCK.push_back({ v[i][j].first,v[i][j].second });
                CUR_TRUCK_KG += v[i][j].second;
                RESULT += v[i][j].second;
            }
            //일부만 실을 수 있는 경우
            else if (CUR_TRUCK_KG + v[i][j].second > TRUCK && CUR_TRUCK_KG != TRUCK) {
                int MINUS_KG = 0;

                CUR_TRUCK_KG += v[i][j].second;
                MINUS_KG = CUR_TRUCK_KG - TRUCK;

                CUR_TRUCK_KG = TRUCK;
                MOVING_TRUCK.push_back({ v[i][j].first,v[i][j].second - MINUS_KG });
                RESULT += v[i][j].second - MINUS_KG;
            }
            //택배가 꽉찼는데 지금 배송하는 택배보다 나중에 도착하는 택배가 있을경우
            //우선순위가 다르기 때문에 버린다.
            else {
                for (int z = 0; z < MOVING_TRUCK.size(); z++) {
                    //현재 배송할 수 있는 마을 보다 트럭에 있는 도착지 마을이 클 경우
                    //어차피 여기까지 온건 이미 택배가 꽉찬 상태임
                    //RESULT는 변하지 않음
                    if (MOVING_TRUCK[z].first > v[i][j].first) {
                        int MINUS_KG = 0;
                        //과거 세컨드
                        int AEQ = MOVING_TRUCK[z].second;
                        //현재 세컨드 초기화
                        MOVING_TRUCK[z].second = 0;

                        CUR_TRUCK_KG -= AEQ;
                        //그냥 전체를 실을 수 있는 경우
                        if (CUR_TRUCK_KG + v[i][j].second <= TRUCK) {
                            MOVING_TRUCK.push_back({ v[i][j].first,v[i][j].second });
                            CUR_TRUCK_KG += v[i][j].second;
                            v[i][j].second = 0;
                        }
                        //일부만 실을 수 있는 경우
                        else if (CUR_TRUCK_KG + v[i][j].second > TRUCK) {
                            int MINUS_KG = 0;

                            CUR_TRUCK_KG += v[i][j].second;
                            MINUS_KG = CUR_TRUCK_KG - TRUCK;

                            CUR_TRUCK_KG = TRUCK;
                            int k = v[i][j].second - MINUS_KG;
                            MOVING_TRUCK.push_back({ v[i][j].first,k });
                            v[i][j].second -= k;
                        }
                        //이전 택배 넣을 수 있는 경우
                        if (CUR_TRUCK_KG < TRUCK) {
                            //그냥 넣을 수 있는 경우
                            if (CUR_TRUCK_KG + AEQ <= TRUCK) {
                                CUR_TRUCK_KG += AEQ;
                            }
                            //일부만 넣어야 하는 경우
                            else {
                                int MINUS_KG = 0;
                                MINUS_KG = TRUCK - CUR_TRUCK_KG;
                                if (AEQ > MINUS_KG) {
                                    MOVING_TRUCK[z].second = MINUS_KG;
                                }
                                else {
                                    MOVING_TRUCK[z].second = AEQ;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << RESULT;

    return 0;

}