#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int N;
vector<int> NEG;
vector<int> POS;
int RESULT = 0;
bool NEG_CHECK[51];
bool POS_CHECK[51];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (a <= 0) {
            NEG.push_back(a);
        }
        else {
            POS.push_back(a);
        }
    }

    sort(NEG.begin(), NEG.end(), greater<int>());
    sort(POS.begin(), POS.end());

    //음수에서는 곱하기를 진행하면 안됨
    //0이 존재한다면 0과 음수에서 가장 작은 수를 곱해줘야함 

    int NEG_END = NEG.size() - 1;
    int NEG_START = NEG_END - 1;

    int NEG_ZERO_START = 0;


    if (NEG_END >= 1) {
        while (true) {
            if (NEG[NEG_END] == 0) {
                RESULT += NEG[NEG_END] * NEG[NEG_ZERO_START];
                NEG_CHECK[NEG_END] = true;
                NEG_CHECK[NEG_ZERO_START] = true;
                if (NEG_END - 1 <= NEG_ZERO_START) {
                    break;
                }
                else {
                    NEG_END--;
                    NEG_ZERO_START++;
                }
            }
            else {
                RESULT += NEG[NEG_END] * NEG[NEG_START];
                NEG_CHECK[NEG_END] = true;
                NEG_CHECK[NEG_START] = true;
                if (NEG_END - 2 >= 0 && NEG_START - 2 >= 0) {
                    NEG_END -= 2;
                    NEG_START -= 2;
                }
                else {
                    break;
                }
            }
        }
    }

    int POS_END = POS.size() - 1;
    int POS_START = POS.size() - 2;

    //양수에서는 곱하기를 진행해야 함

    if (POS_END >= 1) {
        while (true) {
            if (POS[POS_END] == 1 && POS[POS_START] == 1) {
                break;
            }
            //곱하지 않고 더한게 더 클 경우
            if (POS[POS_END] + POS[POS_START] > POS[POS_END] * POS[POS_START]) {
                if (POS_START - 2 >= 0 && POS_END - 2 >= 0) {
                    POS_END -= 2;
                    POS_START -= 2;
                }
                else {
                    break;
                }
            }
            else {
                RESULT += POS[POS_END] * POS[POS_START];
                POS_CHECK[POS_END] = true;
                POS_CHECK[POS_START] = true;
                if (POS_START - 2 >= 0 && POS_END - 2 >= 0) {
                    POS_END -= 2;
                    POS_START -= 2;
                }
                else {
                    break;
                }
            }
        }
    }

    for (int i = 0; i < POS.size(); i++) {
        if (POS_CHECK[i] == false) {
            RESULT += POS[i];
        }
    }


    for (int i = 0; i < NEG.size(); i++) {
        if (NEG_CHECK[i] == false) {
            RESULT += NEG[i];
        }
    }



    cout << RESULT;

    return 0;

}
