#include<bits/stdc++.h>
using namespace std;
const int N=2e5+111;
vector<int>g[N];
vector<int>parent(N,-1),d(N,0),mark(N,0);
vector<int>path;
void bfs(int x,int dest){
  queue<int>q;
  q.push(x);
  mark[x]=1;
  while(!q.empty()){
    int k=q.front();
    q.pop();
    if(k==dest){printf("shortest distance is :-> %d\n",d[k]);break;}
    for(auto i:g[k])
      if(!mark[i]){
        parent[i]=k;
        q.push(i);
        mark[i]=1;
        d[i]=d[k]+1;
      }
    }
    int k=dest;
    while(k!=x){
      path.push_back(k);
      k=parent[k];
    }
    path.push_back(k);
    for(int i=path.size()-1;i>=1;i--)printf("%d -> ",path[i]);
    printf("%d\n",path[0]);
}
void solve(){
  int n,m;
  scanf("%d %d",&n,&m);
  int x,y;
  for(int i=1;i<=m;i++){
    scanf("%d %d",&x,&y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
  bfs(1,6);
}
int main(){
  solve();
}
