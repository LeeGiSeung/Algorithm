#include <iostream>
using namespace std;

int main(){
    int a, b, c, reward=0;
    cin >> a >> b >> c;
    
    if (a==b && b==c){ //같은 눈이 3개일 때
        reward = 10000 + a*1000;
    }
    else if (a==b || a==c){ //같은 눈이 2개일 대
        reward = 1000 + a*100;
    }
    else if (b==c){ //같은 눈이 2개일 때
        reward = 1000 + b*100;
    }
    else { //모두 다른 눈일 때
        reward = max(max(a,b),c) * 100;
    }
    
    cout << reward;
    
    return 0;
} 