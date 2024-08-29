#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char map[13][7];
bool canDelete[13][7] = { false };
int dx[4] = {-1,1,0,0};
int dy[4] = { 0,0,-1,1 };
int result = 0;

struct DATA {
    int x, y;
};

void input() {
    for (int i = 0; i < 12; i++) {
        cin >> map[i];
    }
}

bool puyopuyo(int x, int y, char c) {
    bool check[13][7] = { false };
    queue<DATA> q;
    vector<DATA> same;
    
    q.push({x, y});
    check[x][y] = true;
    same.push_back({x, y});
    
    while (!q.empty()) {
        int cx = q.front().x;
        int cy = q.front().y;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if (0 <= nx && nx < 12 && 0 <= ny && ny < 6 && !check[nx][ny] && map[nx][ny] == c) {
                q.push({nx, ny});
                check[nx][ny] = true;
                same.push_back({nx, ny});
            }
        }
    }
    
    if (same.size() >= 4) {
        for (auto &p : same) {
            canDelete[p.x][p.y] = true;
        }
        return true;
    }
    
    return false;
}

void puyopuyoDelete() {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            if (canDelete[i][j]) {
                map[i][j] = '.';
                canDelete[i][j] = false;
            }
        }
    }
}

void applyGravity() {
    for (int j = 0; j < 6; j++) {
        for (int i = 11; i >= 0; i--) {
            if (map[i][j] != '.') {
                int k = i;
                while (k + 1 < 12 && map[k + 1][j] == '.') {
                    map[k + 1][j] = map[k][j];
                    map[k][j] = '.';
                    k++;
                }
            }
        }
    }
}

void solve() {
    bool chainOccurred;
    
    do {
        chainOccurred = false;
        
        for (int i = 11; i >= 0; i--) {
            for (int j = 0; j < 6; j++) {
                if (map[i][j] != '.' && puyopuyo(i, j, map[i][j])) {
                    chainOccurred = true;
                }
            }
        }
        
        if (chainOccurred) {
            result++;
            puyopuyoDelete();
            applyGravity();
        }
        
    } while (chainOccurred);
    
    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    input();
    solve();
    
    return 0;
}
