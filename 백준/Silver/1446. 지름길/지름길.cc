#include <bits/stdc++.h>

#define MAX 10001
#define INF 987654321

using namespace std;
using pii=pair<int, int>;

vector<pii> vec[MAX];
vector<int> dist(MAX, INF);

int main(){
    int N, D; cin>>N>>D;
    
    while(N--){
        int s,e,w; cin>>s>>e>>w;
        if(e>D)continue;
        vec[e].push_back({s, w});
    }
    
    dist[0]=0;
    
    for(int i=1; i<=D; i++){
        if(vec[i].size()==0) dist[i]=dist[i-1]+1;
        else{
            for(auto d: vec[i])
                dist[i]=min(dist[i], min(dist[i-1]+1, dist[d.first]+d.second));
        }
    }

    cout<<dist[D];
    
    return 0;
}