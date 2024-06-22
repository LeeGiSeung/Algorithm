#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

bool team[20] = {};
int score[20][20] = {};
int N, mymin = 99999999;
void teamset(int idx, int cnt)
{
    vector<int> start; // 스타트 팀원의 인덱스값
    vector<int> link; // 링크팀 팀원의 인덱스값
    int start_score = 0;
    int link_score = 0;
    if(cnt == (N/2))
    {
        for(int i = 0; i < N; i++)
        {
            if(team[i] == true) // 선택된 사람들은 start팀에
                start.push_back(i);
            else // 그 외의 사람들은 link팀으로
                link.push_back(i);
        }
        for(int i = 0; i < (N/2); i++)
            for(int j = 0; j < (N/2); j++)
            {
                start_score += score[start[i]][start[j]];
                link_score += score[link[i]][link[j]];
            } // 각 팀의 능력치의 합 계산
        if(abs(start_score - link_score) < mymin)
            mymin = abs(start_score - link_score);
        return;
    }
    for(int i = idx; i < N; i++)
    {
        if(team[i])
            continue;
        else
        {
            team[i] = true;
            teamset(i,cnt+1);
            team[i] = false;
        }
    }
}
int main() {
    scanf("%d",&N);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf("%d",&score[i][j]);
    teamset(0,0);
    printf("%d",mymin);
}