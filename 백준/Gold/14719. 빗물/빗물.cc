#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{       
    int m, n; 
    cin >> m >> n; 
    vector <int> v; 
    for (int i = 0; i < n; i++) {
        int a; cin >> a; 
        v.push_back(a); 
    }
    int result = 0; 
    for (int i = 1; i < n - 1; i++) {
        int l = 0; 
        int r = 0; 
        for (int j = 0; j < i; j++) {
            if (v[i] < v[j])l = max(l, v[j]); 
        }
        for (int j = i + 1; j < n; j++) {
            if (v[i] < v[j])r = max(r, v[j]); 
        }
        if(l&&r)result+= min(l, r) - v[i]; 
    }
    cout << result; 

}