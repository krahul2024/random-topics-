// ctrl+alt+f for formatting
//in this problem we have to find max distance from every node this approach uses diameter concept 
//involving 3 dfs. 2 dfs are for finding diametrically opposite nodes and then we find distances wrt to both
//nodes and take max of the distances for every node.
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 11, mod = 1e9 + 7;
#define pb push_back
#define all(x) begin(x),end(x)
vector<int>g[N],mark(N,0),dist(N,0);
void dfs(int x){
    mark[x]=1;
    for(int i:g[x])if(!mark[i]){
        dist[i]=dist[x]+1;
        dfs(i);
    }
}
void solve(){
    int n;
    scanf("%d",&n);
    int x,y;
    if(n==1){
        printf("0\n");
        return;
    }
    for(int i=1;i<n;i++){
        scanf("%d %d",&x,&y);
        g[x].pb(y);
        g[y].pb(x);
    }
    int node1,node2,diameter,mx=0;
    dfs(1);
    for(int i=1;i<=n;i++)
        if(dist[i]>mx)mx=dist[i],node1=i;
    mark.assign(N,0);
    dist.assign(N,0);
    mx=0;
    dfs(node1);
    for(int i=1;i<=n;i++)
        if(dist[i]>mx and i!=node1)mx=dist[i],node2=i;
    diameter=mx;
    mark.assign(N,0);
    vector<int>dist1=dist;
    dist.assign(N,0);
    dfs(node2);
    for(int i=1;i<=n;i++)cout<<max(dist[i],dist1[i])<<' ';
        puts("");

    
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); //file input.txt is opened in reading mode i.e "r"
    freopen("output.txt", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif
    solve();
}
