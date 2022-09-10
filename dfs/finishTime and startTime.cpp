#include<bits/stdc++.h>
using namespace std;
#define pb push_back 
#define all(a) begin(a),end(a)
// #define int long long int
const int N=1e5+111;
vector<int>g[N];
vector<int>st(N,0),ft(N,0),mark(N,0),d(N,0),parent(N,0);
bool cyc=0;
int t=0;
// this is for finding finish time and starting time using dfs traversal
void dfs(int x){
  mark[x]=1;
  t+=1;
  st[x]=t;
  for(auto i:g[x])if(!mark[i])dfs(i);
  t+=1;
  ft[x]=t;
}
void solve(){
  int n,m;
  scanf("%d %d",&n,&m);
  int x,y;
  for(int i=0;i<m;i++){
    scanf("%d %d",&x,&y);
    g[x].pb(y);
//     g[y].pb(x); //commented to make it directed graph
  }
  for(int i=1;i<=n;i++)printf("%d %d\n",st[i],ft[i]);
  
  
}


int main(){
  // int t;
  // in(t);
  // while(t--)
  solve();
}
