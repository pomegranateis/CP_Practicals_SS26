#include <bits/stdc++.h>
using namespace std;

const int MAXN=100005;
int seg[4*MAXN],N,K,Q;

void build(vector<int>&A,int node,int l,int r){
    if(l==r){seg[node]=A[l];return;}
    int m=(l+r)/2;
    build(A,2*node,l,m);
    build(A,2*node+1,m+1,r);
    seg[node]=max(seg[2*node],seg[2*node+1]);
}
void update(int node,int l,int r,int pos,int val){
    if(l==r){seg[node]=val;return;}
    int m=(l+r)/2;
    if(pos<=m) update(2*node,l,m,pos,val);
    else update(2*node+1,m+1,r,pos,val);
    seg[node]=max(seg[2*node],seg[2*node+1]);
}
int query(int node,int l,int r,int ql,int qr){
    if(ql>r||qr<l) return INT_MIN;
    if(ql<=l&&r<=qr) return seg[node];
    int m=(l+r)/2;
    return max(query(2*node,l,m,ql,qr),query(2*node+1,m+1,r,ql,qr));
}

int main(){
    cin>>N>>K>>Q;
    vector<int> A(N+1);
    for(int i=1;i<=N;i++) cin>>A[i];
    build(A,1,1,N);
    while(Q--){
        int t; cin>>t;
        if(t==1){
            int pos,val; cin>>pos>>val;
            update(1,1,N,pos,val);
        } else {
            int i; cin>>i;
            int l=max(1,i-K+1);
            cout<<query(1,1,N,l,i)<<"\n";
        }
    }
}