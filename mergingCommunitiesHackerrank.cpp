// tthis is basic implementation of dsu in the form of queries. quite simple
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+111,mod=1e9+7;
#define pb push_back
#define int long long int
#define all(x) begin(x),end(x)
vector<int>parent(N),size(N,1);

void make_set(int x){
  parent[x]=x;
  size[x]=1;
}
int find(int x){
  if(x==parent[x]) return x;
  return parent[x]=find(parent[x]);
}
void union_set (int x,int y){
  x=find(x),y=find(y);
    if(x!=y){
    if(size[x]<size[y])swap(x,y);
    parent[y]=x;
    size[x]+=size[y];
  }
  else return;
}


void solve(){
 int n,m,x,y;
 char q;
 scanf("%lld %lld",&n,&m);
 for(int i=1;i<=n;i++)make_set(i);
  while(m>0){
    scanf("%c",&q);
    if(q=='Q'){
      scanf("%lld",&x);
      printf("%lld\n",size[find(x)]);
      m--;
    }
    else if(q=='M'){
      scanf("%lld %lld",&x,&y);
      union_set(x,y);
      m--;
    }
  }
 return; 
}





void test(){
  int t;
  scanf("%lld",&t);
  while(t--)solve();
}
signed main(){
  #ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin); //file input.txt is opened in reading mode i.e "r"
freopen("output.txt","w",stdout);  //file output.txt is opened in writing mode i.e "w"
#endif
  // test();
  solve();
}
