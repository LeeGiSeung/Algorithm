#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define Y first
#define X second
using namespace std;
int n,m;
int a[104][104];
bool vst[104][104];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
vector<pair<pair<int,int>, bool>> v;
vector<pair<int,int>> cheese;
queue<pair<int,int>> qq;

void air() { 
	queue<pair<int,int>> q;
	q.push({0,0});
	vst[0][0] = 1;
	while(!q.empty()){
		auto cur = q.front(); q.pop();
		for(int dir=0; dir<4; dir++){
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if(!vst[ny][nx]){
				vst[ny][nx] =1;
				q.push({ny,nx});
			}
			
		}
	}
}

void find() {
	cheese.clear();
	for(int i=0; i<v.size(); i++){
		if(v[i].second) continue;
		int y = v[i].first.first;
		int x = v[i].first.second;
		int cnt = 0;
		for(int dir=0; dir<4; dir++){
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if(a[ny][nx] == 0 && vst[ny][nx]) cnt++;
		}
		if(cnt >= 2){
			cheese.push_back({y,x});
			v[i].second = true;
		}
	}
}

void melt() {
	for(int i=0; i<cheese.size(); i++){
		int y = cheese[i].first;
		int x = cheese[i].second;
		a[y][x] = 0;
		qq.push({y,x});
	}
}

void add() {
	while(!qq.empty()){
		auto cur = qq.front(); qq.pop();
		vst[cur.Y][cur.X] = 1;
		for(int dir=0; dir<4; dir++){
			int ny = cur.Y + dy[dir];
			int nx = cur.X + dx[dir];
			if(!vst[ny][nx]){
				vst[ny][nx] = 1;
				qq.push({ny,nx});
			}
		}
	}
}

bool chk() {
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(a[i][j] == 1) return false;
		}
	}
	return true;
}

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> a[i][j];
			if(a[i][j] == 1){
				v.push_back({{i,j}, false});
				vst[i][j] = 1;
			}
		}
	}
	int ret = 0;
	air();
	while(1){
		if(chk()) break;
		find();
		melt();
		add();
		ret++;
	}
	cout << ret;
	return 0;
}