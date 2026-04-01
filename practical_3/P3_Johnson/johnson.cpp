#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (1LL<<60);
struct Edge{int u,v; ll w;};

struct DSU{int n; vector<int> p; DSU(int n):n(n),p(n){iota(p.begin(),p.end(),0);}int find(int a){return p[a]==a?a:p[a]=find(p[a]);} };

int main(){
    // reuse Floyd graph (5 nodes)
    int V=5;
    vector<Edge> edges;
    edges.push_back({0,1,3}); edges.push_back({0,2,8}); edges.push_back({1,3,1}); edges.push_back({1,4,7}); edges.push_back({2,1,4}); edges.push_back({3,0,2}); edges.push_back({3,2,-5}); edges.push_back({4,3,6});
    // Bellman-Ford from s (node V) to compute h
    int s=V; int N=V+1;
    vector<ll> h(N, INF); h[s]=0;
    vector<Edge> edges2 = edges;
    for(int i=0;i<V;i++) edges2.push_back({s,i,0});
    for(int _=0;_<N-1;_++){
        for(auto &e: edges2){ if(h[e.u]<INF && h[e.u]+e.w < h[e.v]) h[e.v]=h[e.u]+e.w; }
    }
    // check negative cycle
    bool neg=false; for(auto &e:edges2) if(h[e.u]<INF && h[e.u]+e.w < h[e.v]) neg=true;
    if(neg){ cout<<"Negative cycle detected\n"; return 0; }
    // reweight
    vector<vector<pair<int,ll>>> adj(V);
    for(auto &e:edges){ ll w2 = e.w + h[e.u] - h[e.v]; adj[e.u].push_back({e.v,w2}); }
    // run Dijkstra from each node
    vector<vector<ll>> dist(V, vector<ll>(V, INF));
    for(int src=0;src<V;src++){
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
        dist[src][src]=0; pq.push({0,src});
        while(!pq.empty()){
            auto [d,u]=pq.top(); pq.pop(); if(d!=dist[src][u]) continue;
            for(auto [v,w]:adj[u]){
                if(d+w < dist[src][v]){ dist[src][v]=d+w; pq.push({dist[src][v], v}); }
            }
        }
    }
    // recover true distances
    cout<<"Recovered distance matrix:\n";
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(dist[i][j]>=INF) cout<<"INF "; else cout<< (dist[i][j] - h[i] + h[j]) <<" ";
        }
        cout<<"\n";
    }
}
