#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int n; vector<int> p, r;
    DSU(int n): n(n), p(n), r(n,0){ iota(p.begin(), p.end(), 0); }
    int find(int a){ return p[a]==a? a : p[a]=find(p[a]); }
    bool unite(int a,int b){ a=find(a); b=find(b); if(a==b) return false; if(r[a]<r[b]) swap(a,b); p[b]=a; if(r[a]==r[b]) r[a]++; return true; }
};

int main(){
    // Graph from prompt
    vector<tuple<int,int,int>> edges = {
        {0,1,4},{0,2,3},{1,2,1},{1,3,5},{2,3,6},{2,4,2},{3,4,8},{3,5,7},{4,5,9},{4,6,3},{5,6,4}
    };
    int V=7;
    DSU dsu(V);
    vector<tuple<int,int,int>> mst;
    int components = V;
    while(components>1){
        vector<int> cheapest(V, -1);
        for(int i=0;i<edges.size();i++){
            auto [u,v,w]=edges[i];
            int a=dsu.find(u), b=dsu.find(v);
            if(a==b) continue;
            if(cheapest[a]==-1 || get<2>(edges[cheapest[a]])>w) cheapest[a]=i;
            if(cheapest[b]==-1 || get<2>(edges[cheapest[b]])>w) cheapest[b]=i;
        }
        bool any=false;
        for(int i=0;i<V;i++){
            if(cheapest[i]!=-1){
                auto [u,v,w]=edges[cheapest[i]];
                if(dsu.unite(u,v)){
                    mst.push_back(edges[cheapest[i]]);
                    components--; any=true;
                }
            }
        }
        if(!any) break;
    }
    int total=0; cout<<"MST edges:\n";
    for(auto [u,v,w]:mst){ cout<<u<<"-"<<v<<":"<<w<<"\n"; total+=w; }
    cout<<"Total weight="<<total<<"\n";
}
