#include <iostream>
#include <stack>
#include <cctype> 
#include <vector>
#include <queue>

using namespace std;

int N, M;
//구름이동
int dx[8] = {-1,-1,0,1,1,1,0,-1}; 
int dy[8] = {0,-1,-1,-1,0,1,1,1};

//대각선 확인
int ddx[4] = {-1,1,-1,1};
int ddy[4] = {-1,-1,1,1};

vector<vector<int>> mapVec;
vector<vector<bool>> isCloud;

//원형으로 이어주기 위한 확인함수
int isBoundary(int x) {
    if (x > N) {
        x = x%N;
    }
    
    if (x < 1) {
        x = N + (x % N);
    }

    return x;
}
void move(int d, int s) {
    vector<vector<bool>> tempCloud(N + 1, vector<bool>(N + 1, false));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (isCloud[i][j]) { 
                int ny = isBoundary(i + (s * dy[d - 1]));
                int nx = isBoundary(j + (s * dx[d - 1]));  

                tempCloud[ny][nx] = true; 
                mapVec[ny][nx] += 1;   
            }
        }
    }

    isCloud = tempCloud;  
}

void waterCopy() {

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {

            if (isCloud[i][j]) {
                int count = 0;
                for (int dir = 0; dir < 4; dir++) {
                    int nx = j + ddx[dir], ny = i + ddy[dir];
                    if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && mapVec[ny][nx] > 0) {
                        count++;
                    }
                }
                mapVec[i][j] += count;
            }
        }
    }


}

void makeCloud() {
    vector<vector<bool>> newCloud(N + 1, vector<bool>(N + 1, false));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (!isCloud[i][j] && mapVec[i][j] >= 2) {
                newCloud[i][j] = true;
                mapVec[i][j] -= 2;
            }
        }
    }
    isCloud = newCloud;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;


    mapVec.resize(N+1, vector<int>(N + 1, 0));
    isCloud.resize(N + 1, vector<bool>(N + 1, false));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> mapVec[i][j];
        }
    }

    isCloud[N][1] = true;
    isCloud[N][2] = true;
    isCloud[N-1][1] = true;
    isCloud[N-1][2] = true;
   
    for (int i = 0; i < M; i++) {
        int d, s;
        cin >> d >> s;

        move(d, s);
        waterCopy();
        makeCloud();
    }

    //물 합산
    int result = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {  
            result += mapVec[i][j];
        }
    }

    cout << result << '\n';

    return 0;
}