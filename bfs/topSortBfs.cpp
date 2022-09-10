#include<bits/stdc++.h>
using namespace std;
const int N=2e5+111;
vector<int>g[N];
vector<int>mark(N,0),inDeg(N,0),tSort;
void bfs(int x){
  queue<int>q;
  q.push(x);
  mark[x]=1;
  while(!q.empty()){
    int k=q.front();q.pop();
    // tSort.push_back(k);
    printf("%d ",k);
    for(auto i:g[k]){
      // simple logic is to push all neighbours with indegree one or first decrease one from
      // them and then push those with zero indegree, zero indegree ensures that it follows no node
      if(!mark[i])inDeg[i]--;
      if(inDeg[i]==0)q.push(i),mark[i]=1;
    }
  }
}
void solve(){
  int n,m;
  cin>>n>>m;
  int x,y;
  for(int i=1;i<=m;i++){
    cin>>x>>y;
    g[x].push_back(y);
  }
  // calculation of indegree of a node
  for(int i=1;i<=n;i++)for(auto j:g[i])inDeg[j]++;
   printf("Topological sorting(one of the many sortings) is\n");
   int count=0;
  for(int i=1;i<=n;i++)if(!mark[i] and inDeg[i]==0){
    printf("Component number : %d-> ",count+=1);
    bfs(i);
    puts("");
  }
  // it can be seen that after visiting all nodes indgree of all nodes becomes zero;
  // for(int i=1;i<=n;i++)printf("%d ",inDeg[i]);
  
}
int main(){
  solve();
}
