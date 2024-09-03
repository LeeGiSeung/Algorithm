#include <cstdio>
#include <queue>
#include <string.h>
using namespace std;
 
const int dx[] = { 1,-1,0,0 };
const int dy[] = { 0,0,1,-1 };
 
struct CAR
{
	int y, x;
	int fuel;
}Taxi;
 
struct PERSON
{
	int y, x;
	int goal_y, goal_x;
}Person[401];	//1~400
 
struct COORD 
{
	COORD(){}
	COORD(int y_, int x_, int dist_ = 0) { y = y_; x = x_; dist = dist_; }
	int y, x;
	int dist;
};
 
int n, m;
int map[21][21];
 
int main()
{
	scanf("%d %d %d", &n, &m, &Taxi.fuel);
 
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1)
				map[i][j] = -1;
		}
 
	scanf("%d %d", &Taxi.y, &Taxi.x);
 
	for (int i = 1; i <= m; ++i) {
		scanf("%d %d %d %d", &Person[i].y, &Person[i].x, &Person[i].goal_y, &Person[i].goal_x);
		map[Person[i].y][Person[i].x] = i;
	}
	
 
	while (1)
	{
		queue<COORD> q;
		bool visited[21][21];
		memset(visited, false, sizeof(visited));
 
		visited[Taxi.y][Taxi.x] = true;
		q.push(COORD(Taxi.y, Taxi.x));
 
		int candinum = -1;
		COORD candi;
		int usefuel = 0;
 
		while (!q.empty())
		{
			COORD cur = q.front(); q.pop();
 
			if (map[cur.y][cur.x] > 0)
			{
				if (candinum == -1)
				{
					candinum = map[cur.y][cur.x];
					candi = cur;
					usefuel = cur.dist;
				}
				else
				{
					if (candi.dist < cur.dist)
						break;
 
					if (candi.y > cur.y)
					{
						candinum = map[cur.y][cur.x];
						candi = cur;
						usefuel = cur.dist;
					}
					else if (candi.y == cur.y)
					{
						if (candi.x > cur.x)
						{
							candinum = map[cur.y][cur.x];
							candi = cur;
							usefuel = cur.dist;
						}
					}
				}
			}
 
			for (int dir = 0; dir < 4; ++dir)
			{
				COORD next;
				next.y = cur.y + dy[dir];
				next.x = cur.x + dx[dir];
				next.dist = cur.dist + 1;
 
				if (next.y < 1 || next.x < 1 || next.x > n || next.y > n || visited[next.y][next.x] || map[next.y][next.x] == -1)
					continue;
 
				visited[next.y][next.x] = true;
				q.push(next);
			}
 
		}
 
		if (candinum != -1) {
			map[Person[candinum].y][Person[candinum].x] = 0;
			Taxi.y = Person[candinum].y;
			Taxi.x = Person[candinum].x;
			Taxi.fuel -= usefuel;
 
			if (Taxi.fuel < 0)
			{
				printf("-1");
				break;
			}
 
		}
		else
		{
			printf("-1");
			break;
		}
		
		q = queue<COORD>();
		memset(visited, false, sizeof(visited));
 
		visited[Taxi.y][Taxi.x] = true;
		q.push(COORD(Taxi.y, Taxi.x));
 
		bool arrived = false;
		int usefuelarrived = 0;
 
		while (!q.empty())
		{
			COORD cur = q.front(); q.pop();
 
			if (cur.y == Person[candinum].goal_y && cur.x == Person[candinum].goal_x)
			{
				arrived = true;
				usefuelarrived = cur.dist;
				break;
			}
 
			for (int dir = 0; dir < 4; ++dir)
			{
				COORD next;
				next.y = cur.y + dy[dir];
				next.x = cur.x + dx[dir];
				next.dist = cur.dist + 1;
 
				if (next.y < 1 || next.x < 1 || next.x > n || next.y > n || visited[next.y][next.x] || map[next.y][next.x] == -1)
					continue;
 
				visited[next.y][next.x] = true;
				q.push(next);
			}
		}
 
		if (!arrived)
		{
			printf("-1");
			break;
		}
 
		Taxi.y = Person[candinum].goal_y;
		Taxi.x = Person[candinum].goal_x;
		Taxi.fuel -= usefuelarrived;
 
		if (Taxi.fuel < 0)
		{
			printf("-1");
			break;
		}
 
 
		Taxi.fuel += (usefuelarrived * 2);
		--m;
 
		if (m == 0)
		{
			printf("%d", Taxi.fuel);
			break;
		}
	}
 
 
	return 0;
}