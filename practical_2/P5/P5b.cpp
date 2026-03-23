#include <bits/stdc++.h>
using namespace std;
typedef pair<double,int> pdi;
int main(){
    int N,M; cin>>N>>M;
    vector<vector<tuple<int,double,double>>> adj(N+1);
    for(int i=0;i<M;i++){
        int u,v; double a,b; cin>>u>>v>>a>>b;
        adj[u].push_back({v,a,b});
    }
    vector<double> dist(N+1,1e18);
    priority_queue<pdi,vector<pdi>,greater<pdi>> pq;
    dist[1]=0.0; pq.push({0.0,1});
    while(!pq.empty()){
        auto [d,u]=pq.top(); pq.pop();
        if(d>dist[u]+1e-9) continue;
        for(auto &[v,a,b]:adj[u]){
            double arrive = d*(1.0+a)+b;
            if(arrive < dist[v]-1e-9){
                dist[v]=arrive;
                pq.push({arrive,v});
            }
        }
    }
    if(dist[N]>=1e17) cout<<-1<<"\n";
    else cout<<fixed<<setprecision(2)<<dist[N]<<"\n";
}