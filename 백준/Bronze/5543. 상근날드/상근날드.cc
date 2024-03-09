#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
    int burger1, burger2, burger3, coke, sprite;
    cin >> burger1;
    cin >> burger2;
    cin >> burger3;
    cin >> coke;
    cin >> sprite;
 
    int burgerMin = min(burger1, burger2);
    burgerMin = min(burgerMin, burger3);
    int drinkMin = min(coke, sprite);
    int minPrice = burgerMin + drinkMin - 50;
    cout << minPrice << endl;
    
    return 0;
}
