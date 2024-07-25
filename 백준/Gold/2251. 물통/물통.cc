#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <deque>
#include <set>


using namespace std;
int max_a, max_b, max_c;

bool visit[201][201][201] = { false };

set<int> result;
int mv;
int na, nb, nc;
void bfs() {

    queue < pair<pair<int, int>, int >> q;

    q.push({ {0,0},max_c });

    result.insert(max_c);

    while (!q.empty()) {

        int ia = q.front().first.first;
        int ib = q.front().first.second;
        int ic = q.front().second;
        q.pop();

        if (visit[ia][ib][ic] == true) {
            continue;
        }

        visit[ia][ib][ic] = true;

        //a에서 움직임
        if (ia != 0) {
            if (ib != max_b) {
                mv = min(ia,max_b - ib);
                na = ia - mv;
                nb = ib + mv;
                nc = ic;
                q.push({ {na,nb},nc });
                if (na == 0 && visit[na][nb][nc] == false) {
                    result.insert(nc);
                }
            }
            if (ic != max_c) {
                mv = min(ia,max_c - ic);
                na = ia - mv;
                nb = ib;
                nc = ic + mv;
                q.push({ {na,nb},nc });
                if (na == 0 && visit[na][nb][nc] == false) {
                    result.insert(nc);
                }
            }
        }

        //b에서 움직임
        if (ib != 0) {
            if (ia != max_a) {
                mv = min(ib,max_a - ia);
                na = ia + mv;
                nb = ib - mv;
                nc = ic;
                q.push({ {na,nb},nc });
                if (na == 0 && visit[na][nb][nc] == false) {
                    result.insert(nc);
                }
            }
            if (ic != max_c) {
                mv = min(ib,max_c - ic);
                na = ia;
                nb = ib - mv;
                nc = ic + mv;
                q.push({ {na,nb},nc });
                if (na == 0 && visit[na][nb][nc] == false) {
                    result.insert(nc);
                }
            }
        }

        //c에서 움직임
        if (ic != 0) {
            if (ib != max_b) {
                mv = min(ic,max_b - ib);
                na = ia;
                nb = ib + mv;
                nc = ic - mv;
                q.push({ {na,nb},nc });
                    if (na == 0 && visit[na][nb][nc] == false) {
                    result.insert(nc);
                }
            }
            if (ia != max_a) {
                mv = min(ic,max_a - ia);
                na = ia + mv;
                nb = ib;
                nc = ic - mv;
                q.push({ {na,nb},nc });
                if (na == 0 && visit[na][nb][nc] == false) {
                    result.insert(nc);
                }
            }
        }
        

    }

    for (int value : result){
        cout << value << " ";
    }


}

int main() {

    cin >> max_a >> max_b >> max_c;
 
    bfs();

    return 0;
}
