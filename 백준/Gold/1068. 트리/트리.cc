#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

#define endl "\n"

using namespace std;
int n, k;

vector<int> v[51];

int root_node;
int out_node;
int reaf_node = 0;


void input() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == -1) {
            root_node = i;
        }
        else {
            v[a].push_back(i);
        }
    }

    //out node
    cin >> out_node;

}

int solve(int in) {
    if (in == out_node) return -1;
    if (!v[in].size()) {
        reaf_node++;
        return 0;
    }
    for (int i = 0; i < v[in].size(); i++) {
        int tmp = solve(v[in][i]);
        if (tmp == -1 && v[in].size() == 1) {
            reaf_node++;
        }
    } 
    return 0;
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

    input();C
    solve(root_node);
    cout << reaf_node << endl;
    return 0;
}
profile
Ki
