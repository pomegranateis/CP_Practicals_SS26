#include <bits/stdc++.h>
using namespace std;

int N;
int mask[21];
bool dp[1<<20][20];

int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>N;
        for(int i=0;i<N;i++){
            int m; cin>>m;
            mask[i]=0;
            for(int j=0;j<m;j++){
                int x; cin>>x; x--;
                mask[i]|=(1<<x);
            }
        }

        memset(dp,false,sizeof(dp));
        for(int i=0;i<N;i++) dp[1<<i][i]=true;
        
        for(int s=1;s<(1<<N);s++){
            for(int last=0;last<N;last++){
                if(!dp[s][last]) continue;
                for(int next=0;next<N;next++){
                    if(s&(1<<next)) continue;
                    if(mask[last]&mask[next]) continue;
                    dp[s|(1<<next)][next]=true;
                }
            }
        }
        
        int full=(1<<N)-1;
        bool ok=false;
        if(N==1){ok=true;}
        else{
            for(int last=1;last<N;last++){
                if(dp[full][last] && !(mask[last]&mask[0])){
                    ok=true; break;
                }
            }
        }
        cout<<(ok?"YES":"NO")<<"\n";
    }
}