#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

#define endl "\n"

using namespace std;
int n, k;
int out = 0;

deque<int> rail;
deque<bool> robot;

void input() {
    cin >> n >> k;
    for (int i = 0; i < (n * 2); i++) {
        int a;
        cin >> a;
        rail.push_back(a);
        robot.push_back(false);
    }
}

void rotate() {
    rail.push_front(rail.back());
    rail.pop_back();

    robot.push_front(robot.back());
    robot.pop_back();

    robot[n - 1] = false;
}

void robotmove() {
    for (int i = n - 2; i >= 0; i--) {
        if ((robot[i]) && (!robot[i + 1]) && (rail[i + 1] > 0)) {
            robot[i] = false;
            robot[i + 1] = true;
            rail[i + 1]--;
        }
    }
    robot[n - 1] = false; // <- 이 줄을 로봇 이동 루프 밖으로 이동
}

void put() {
    if (rail[0] > 0 && !robot[0]) {
        rail[0]--;
        robot[0] = true;
    }
}

int zerocheck() {
    int check = 0;
    for (int i = 0; i < n * 2; i++) {
        if (rail[i] == 0) {
            check++;
        }
    }
    return check;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

    input();
    int count = 1;

    bool go = true;
    while (go) {
        //1
        rotate();

        //2
        robotmove();

        //3
        put();
        
        int c = zerocheck();
        if (c >= k) {
            cout << count << endl;
            break;
        }

        count++;
    }

    return 0;
}
