//here we are given a tree and we have to calculate sum of diatances from 1 to all other nodes
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+111,mod=1e9+7;
#define pb push_back
#define all(x) begin(x),end(x)
vector<int>g[N],subSize(N,1),mark(N,0),dp(N,0);
int f(int x){
    mark[x]=1;
    int sum=0;
    for(int i:g[x])if(!mark[i])
        sum+=f(i),subSize[x]+=subSize[i];//size of subtree
    return dp[x]=(x==1?sum:sum+=subSize[x]);
}

void solve(){
  int n,x,y;
  cin>>n;
  for(int i=1;i<=n-1;i++){
    cin>>x>>y;
    g[x].push_back(x);
    g[x].push_back(y);
  }
    int sum=f(1);
    for(int i=1;i<=n;i++)cout<<dp[i]<<'\n';
  
}
  int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  solve();
}
