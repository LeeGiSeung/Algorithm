#include <iostream>
 
using namespace std;
 
int main() {
 
    int s,t;
    int sum=0, sum1=0;
    for(int i=0; i<4; i++){
 
        cin>>s;
        sum+=s;
 
    }
 
    for(int j=0; j<4; j++){
 
        cin>>t;
        sum1+=t;
 
    }
 
    if(sum>sum1||sum==sum1) cout<<sum;
    else cout<<sum1;
    
}