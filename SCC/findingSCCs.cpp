// strongly connected components 
// let's consider a scenario: in undir graphs there exists a path b/w every pair of nodes 
// now if a dir graph has same thing that there exists a path b/w every pair of vertices then 
// this type of graph is called strongly connected graph . now consider a scenario when a graph consists of several of these SCGs
// then we call these SCGs as strongly connected components SCCs and these can be found using below algorithm
// to find sccs we have a graph and then we reverse this graph,find finishing time of every node
// in original graph traversal,find topological sorting also, then sort tSort
// array according to descending finishing time. after all this we just have to find
// run a dfs on reversed graph and in this traversal each time we do dfs then we will be traversing a single
// scc or number of traversals is the number of sccs. see the code below if there are some doubts
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+11;
vector<int>g[N],gRev[N];
vector<int>mark(N,0),finishTime(N,0);
vector<int>tSort;
int t=0;
void ts(int x){
    mark[x]=1;
    t++;
    for(auto i:g[x])if(!mark[i])ts(i);
        finishTime[x]=t+=1;
    tSort.push_back(x);
}
void dfs(int x){
    mark[x]=1;
    cout<<x<<" ";
    for(auto i:gRev[x])if(!mark[i])dfs(i);
}
bool comp(int a,int b){
    return finishTime[a]>finishTime[b];
}
void solve(){
  int n,m;
  cin>>n>>m;
  int x,y;
  for(int i=1;i<=m;i++){
    cin>>x>>y;
    //for original graph
    g[x].push_back(y);
    //reversed graph
    gRev[y].push_back(x);
  }
  //finding topoSort and finishing time
  for(int i=1;i<=n;i++)if(!mark[i])ts(i);
    // sorting acc to finishing time
    sort(begin(tSort),end(tSort),comp);
//setting mark array to false again
mark.assign(N,0);
    cout<<"Strongly connected components are\n";
    for(auto i:tSort)if(!mark[i]){
        //running dfs for unmarked nodes in reversed graph
        dfs(i);
        cout<<"\n";
    }
}

void test(){
  long long t;
  scanf("%lld",&t);
  while(t--)solve();
}
int main() 
{
    #ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin); //file input.txt is opened in reading mode i.e "r"
freopen("output.txt","w",stdout);  //file output.txt is opened in writing mode i.e "w"
#endif
  // test();
    solve();
    // rough();
}
