#include <bits/stdc++.h>
using namespace std;
int main(){
    int T; cin>>T;
    while(T--){
        int N,K; cin>>N>>K;
        vector<long long> A(N);
        for(auto &x:A) cin>>x;
        
        long long ans=0;

        long long cur=0;
        for(int b=29;b>=0;b--){
            long long try_val = cur|(1LL<<b);

            int cnt=0;
            bool found=false;
            for(int i=0;i<N;i++){
                if((A[i]&try_val)==try_val) cnt++;
                else cnt=0;
                if(cnt>=K){found=true;break;}
            }
            if(found) cur=try_val;
        }
        cout<<cur<<"\n";
    }
}