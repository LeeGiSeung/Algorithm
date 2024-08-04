#include <iostream>
#include <stack>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  long long ans=0;
  int n;
  cin >> n;
  stack<int> S;
  while(n--){
    int h;
    cin >> h;
    while(!S.empty() && S.top() <= h)
      S.pop();
    
    // 어차피 empty일 때 size는 0이므로 if문을 지워도 된다.
    // 연산의 수를 줄이기 위해 if를 넣었다.
    if(!S.empty())
      ans += S.size();
    S.push(h);
  }
  cout << ans;
}