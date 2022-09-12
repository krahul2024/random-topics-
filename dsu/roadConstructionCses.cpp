// this is also basic implementation of dsu 
// in this question we have to print no. of components and size of largest component after each union
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+111,mod=1e9+7;
#define pb push_back
#define int long long int
#define all(x) begin(x),end(x)
vector<int>parent(N),sz(N,1);
int maxsz=0;
int cnt=0;
void make_set(int x){
  parent[x]=x;
  sz[x]=1;
}
int find(int x){
  if(x==parent[x]) return x;
  return parent[x]=find(parent[x]);
}
void union_set (int x,int y){
  x=find(x),y=find(y);
    if(x!=y){
    if(sz[x]<sz[y])swap(x,y);
    parent[y]=x;
    sz[x]+=sz[y];
    cnt--;
    maxsz=max(maxsz,sz[x]);
  }
  else return;
}

void solve(){
 int n,m,x,y;
 scanf("%lld %lld",&n,&m);
 cnt=n;
 for(int i=1;i<=n;i++)make_set(i);
  for(int i=1;i<=m;i++){
    scanf("%lld %lld",&x,&y);
    union_set(x,y);
    printf("%lld %lld\n",cnt,maxsz);
  }
}

void test(){
  int t;
  scanf("%lld",&t);
  while(t--)solve();
}
signed main(){
  solve();
}
