#include<iostream>
 
#define endl "\n"
#define MAX 20
using namespace std;
 
struct INFO
{
    int Score;
    bool LIVE;
};
 
bool Flag;
int N, Mafia_Idx, Answer;
int Score_Board[MAX][MAX];
INFO Player[MAX];
 
int Min(int A, int B) { if (A < B) return A; return B; }
int Bigger(int A, int B) { if (A > B) return A; return B; }
 
void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> Player[i].Score;
        Player[i].LIVE = true;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> Score_Board[i][j];
        }
    }
    cin >> Mafia_Idx;
}
 
void DFS(int PN, int Day)
{
    if (Flag == true) return;
    if (Player[Mafia_Idx].LIVE == false || PN == 1)
    {
        Answer = Bigger(Answer, Day);
        if (PN == 1 && Player[Mafia_Idx].LIVE == true) Flag = true;
        return;
    }
    
    if (PN % 2 == 0)
    {
        for (int i = 0; i < N; i++)
        {
            if (i == Mafia_Idx) continue;
            if (Player[i].LIVE == false) continue;
 
            Player[i].LIVE = false;
            for (int j = 0; j < N; j++)
            {
                if (Player[j].LIVE == false) continue;
                Player[j].Score = Player[j].Score + Score_Board[i][j];
            }
            DFS(PN - 1, Day + 1);
            if (Flag == true) return;
 
            for (int j = 0; j < N; j++)
            {
                if (Player[j].LIVE == false) continue;
                Player[j].Score = Player[j].Score - Score_Board[i][j];
            }
            Player[i].LIVE = true;
        }
    }
    else
    {
        int Max_Score = 0;
        int Idx = 0;
        for (int i = 0; i < N; i++)
        {
            if (Player[i].LIVE == false) continue;
            
            if (Player[i].Score > Max_Score)
            {
                Max_Score = Player[i].Score;
                Idx = i;
            }
            else if (Player[i].Score == Max_Score) Idx = Min(Idx, i);
        }
 
        Player[Idx].LIVE = false;
        DFS(PN - 1, Day);
        if (Flag == true) return;
        Player[Idx].LIVE = true;
    }
}
 
void Solution()
{
    DFS(N, 0);
    cout << Answer << endl;
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