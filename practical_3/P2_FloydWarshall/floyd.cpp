#include <bits/stdc++.h>
using namespace std;
int main(){
    const int V=5; const int INF=1e9;
    vector<vector<int>> w(V, vector<int>(V, INF));
    for(int i=0;i<V;i++) w[i][i]=0;
    w[0][1]=3; w[0][2]=8; w[1][3]=1; w[1][4]=7; w[2][1]=4; w[3][0]=2; w[3][2]=-5; w[4][3]=6;
    vector<vector<int>> d=w;
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++) for(int j=0;j<V;j++)
            if(d[i][k]<INF && d[k][j]<INF) d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
    }
    cout<<"Final distance matrix:\n";
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(d[i][j]>=INF) cout<<"INF "; else cout<<d[i][j]<<" ";
        }
        cout<<"\n";
    }
    // detect negative cycle
    bool neg=false; for(int i=0;i<V;i++) if(d[i][i]<0) neg=true;
    cout<<"Negative cycle: "<<(neg?"YES":"NO")<<"\n";
}
