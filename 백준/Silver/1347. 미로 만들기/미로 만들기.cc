#include<iostream>
#include<vector>
 
#define endl "\n"
#define MAX 101
using namespace std;
 
int N;
int MAP[MAX][MAX];
vector<char> V;
pair<int, int> Start;
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
 
void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        char a; cin >> a;
        V.push_back(a);
    }
    Start.first = Start.second = 50;
}
 
int Change_Direction(int dir, char cmd)
{
    if (cmd == 'R')
    {
        if (dir == 0) return 2;
        else if (dir == 1) return 3;
        else if (dir == 2) return 1;
        else if (dir == 3) return 0;
    }
    else if (cmd == 'L')
    {
        if (dir == 0) return 3;
        else if (dir == 1) return 2;
        else if (dir == 2) return 0;
        else if (dir == 3) return 1;
    }
}
 
void Solution()
{
    int x = Start.first;
    int y = Start.second;
    int Dir = 2;        // 초기방향 = 남쪽
 
    MAP[x][y] = 1;
 
    for (int i = 0; i < N; i++)
    {
        char D = V[i];
        if (D == 'R' || D == 'L') Dir = Change_Direction(Dir, D);
        else if (D == 'F')
        {
            x = x + dx[Dir];
            y = y + dy[Dir];
            MAP[x][y] = 1;
        }
    }
 
    int sx, sy, ex, ey;
    sx = sy = MAX;
    ex = ey = 0;
 
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            if (MAP[i][j] == 1)
            {
                if (i < sx) sx = i;
                if (j < sy) sy = j;
                if (i > ex) ex = i;
                if (j > ey) ey = j;
            }
        }
    }
 
    for (int i = sx; i <= ex; i++)
    {
        for (int j = sy; j <= ey; j++)
        {
            if (MAP[i][j] == 1) cout << ".";
            else cout << "#";
        }
        cout << endl;
    }
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}
