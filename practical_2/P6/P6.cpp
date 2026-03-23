#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,M,K; cin>>N>>M>>K;
    vector<int> toll(N+1);
    for(int i=1;i<=N;i++) cin>>toll[i];
    
    const int INF=1e9;
    vector<vector<pair<int,int>>> dp(N+1, vector<pair<int,int>>(K+1, {INF,-1}));
    dp[1][0]={0,M};
    
    for(int i=1;i<N;i++){
        for(int k=0;k<=K;k++){
            auto [t,coins]=dp[i][k];
            if(t==INF) continue;
            // Option 1: pay toll[i+1]
            if(coins>=toll[i+1]){
                auto &nxt=dp[i+1][k];
                int nt=t+1, nc=coins-toll[i+1];
                if(nt<nxt.first||(nt==nxt.first&&nc>nxt.second))
                    nxt={nt,nc};
            }
            // Option 2: skip
            if(k<K){
                auto &nxt=dp[i+1][k+1];
                int nt=t+2, nc=coins;
                if(nt<nxt.first||(nt==nxt.first&&nc>nxt.second))
                    nxt={nt,nc};
            }
        }
    }
    
    int ans=INF;
    for(int k=0;k<=K;k++){
        if(dp[N][k].first<ans) ans=dp[N][k].first;
    }
    cout<<(ans==INF?-1:ans)<<"\n";
}