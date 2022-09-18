// this is basic implementation of scc finding we just hav to label the numbers their component number
#include <bits/stdc++.h>
using namespace std;
const long long N=2e5+11;
vector<long long>g[N],gRev[N];
vector<long long>mark(N,0),finishTime(N,0),planet(N,0);
vector<long long>tSort;
long long t=0,cnt=1;
void ts(long long x){
    mark[x]=1;
    t++;
    for(auto i:g[x])if(!mark[i])ts(i);
        finishTime[x]=t+=1;
    tSort.push_back(x);
}
void dfs(long long x){
    mark[x]=1;
    planet[x]=cnt;
    for(auto i:gRev[x])if(!mark[i])dfs(i);
}
bool comp(long long a,long long b){
    return finishTime[a]>finishTime[b];
}
void solve(){
  long long n,m;
  scanf("%lld %lld",&n,&m);
  long long x,y;
  for(long long i=1;i<=m;i++){
    scanf("%lld %lld",&x,&y);
    //for original graph
    g[x].push_back(y);
    //reversed graph
    gRev[y].push_back(x);
  }
  //finding topoSort and finishing time
  for(long long i=1;i<=n;i++)if(!mark[i])ts(i);
    // sorting acc to finishing time
    sort(begin(tSort),end(tSort),comp);
//setting mark array to false again
mark.assign(N,0);
    // cout<<"Strongly connected components are\n";
    for(auto i:tSort)if(!mark[i]){
        //running dfs for unmarked nodes in reversed graph
        dfs(i);
        cnt++;
        // cout<<"\n";
    }
    printf("%lld\n",cnt-1);
    for(long long i=1;i<=n;i++)printf("%lld ",planet[i]);
        printf("\n");
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
