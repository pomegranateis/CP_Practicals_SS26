#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,K; cin>>N>>K;
    vector<int> A(N);
    for(auto &x:A) cin>>x;
    deque<int> dq;
    bool first=true;
    for(int i=0;i<N;i++){
        while(!dq.empty()&&A[dq.back()]<=A[i]) dq.pop_back();
        dq.push_back(i);
        if(dq.front()<i-K+1) dq.pop_front();
        if(i>=K-1){
            if(!first) cout<<" ";
            cout<<A[dq.front()];
            first=false;
        }
    }
    cout<<"\n";
}