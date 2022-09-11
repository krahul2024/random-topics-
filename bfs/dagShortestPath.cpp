#include<bits/stdc++.h>
using namespace std;
const int N=2e5+111;
vector<int>parent(N,-1),d(N,INT_MAX),mark(N,0),inDeg(N,0);
vector<int>tSort;
struct pr{
  int l,r;
}typedef pr;
vector<pr>g[N];
// this is for topological sort of the graph (DAG)
void bfs(int x){
  queue<int>q;
  mark[x]=1;
  q.push(x);
  while(!q.empty()){
    int k=q.front();
    q.pop();
    tSort.push_back(k);
    printf("%d ",k);
    for(auto i:g[k]){
      if(inDeg[i.l]>0)inDeg[i.l]--;
      if(inDeg[i.l]==0)q.push(i.l),mark[i.l]=1;
    }
  }
}

void f(){
  // here we see that if current distance at the node is less than parent 
  // and weight then we update it o/w we let it be as it is. this updation 
  // thing is called relaxation each time we update a distance we say that 
  // an edge is relaxed. it is heavily used in shortest dist problems in graph
  for(auto i:tSort)
    for(auto j:g[i])
      d[j.l]=min(d[j.l],d[i]+j.r);
}

void solve(){
  int n,m;
  scanf("%d %d",&n,&m);
  int x,y,w;
  for(int i=1;i<=m;i++){
    scanf("%d %d %d",&x,&y,&w);
    g[x].push_back({y,w});
  }
  for(int i=1;i<=n;i++)for(auto j:g[i])inDeg[j.l]++;
  for(int i=1;i<=n;i++)if(!mark[i] and inDeg[i]==0)d[i]=0,bfs(i);
  // reverse(begin(tSort),end(tSort));
  f();
  puts("");
  printf("1 is assumed  by default here\nnodes with distances with 0 are unreachable as their indegree is zero\n");
  // for(int i=1;i<=n;i++)
  for(int i=1;i<=n;i++)printf("%d ",d[i]);
}

int main(){
  solve();
}
