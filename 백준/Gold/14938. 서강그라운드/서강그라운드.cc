#include <stdio.h>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int item[105];
vector<pair<int,int> > node[105];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
int value[105];
int n,m,r;
int a,b,l;
int ans;

int Dij(int k){
    for(int i=1;i<=n;i++)
        value[i] = INF;

    value[k] = 0;

    pq.push(make_pair(0,k));

    while(!pq.empty()){
        int x = pq.top().first;
        int U = pq.top().second;
        pq.pop();

        for(int i=0;i<node[U].size();i++){
            int V = node[U][i].first;
            int W = node[U][i].second;

            if(x+W<value[V]){
                value[V] = x+W;
                pq.push(make_pair(x+W,V));
            }
        }
    }

    int sum = 0;

    for(int i=1;i<=n;i++){
        if(value[i]<=m)
            sum+=item[i];
    }

    return sum;
}

int main(){
    scanf("%d %d %d",&n,&m,&r);

    for(int i=1;i<=n;i++)
        scanf("%d",&item[i]);

    for(int i=0;i<r;i++){
        scanf("%d %d %d",&a,&b,&l);

        node[a].push_back(make_pair(b,l));
        node[b].push_back(make_pair(a,l));
    }

    for(int i=1;i<=n;i++)
        ans = max(ans,Dij(i));

    printf("%d",ans);

    return 0;
}