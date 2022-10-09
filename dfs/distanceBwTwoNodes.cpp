// ctrl+alt+f for formatting
in this problem we have to find distance between two nodes 
we can do it using lca like ans=depth[a]+depth[b]-2*depth[lca(a,b)] 
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 11, mod = 1e9 + 7;
#define pb push_back
#define all(x) begin(x),end(x)
vector<int>g[N],mark(N,0),depth(N,0),parent(N,1);
int table[N][20];
void dfs(int x){
    mark[x]=1;
    for(auto i:g[x])if(!mark[i]){
        parent[i]=x;
        table[i][0]=x;
        depth[i]=depth[x]+1;
        dfs(i);
    }
}
int lca(int x,int y){
    if(depth[x]<depth[y])swap(x,y);
    int k=depth[x]-depth[y];
    for(int i=19;i>=0;i--)if(k&(1<<i))x=table[x][i];
    if(x==y) return x;
    for(int i=19;i>=0;i--)
        if(table[x][i]!=table[y][i])x=table[x][i],y=table[y][i];
    return table[x][0];
}
void solve(){
    int n,m,q,x,y,mx,val;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n-1;i++){
        scanf("%d %d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    table[1][0]=1;
    dfs(1);
    for(int i=1;i<=log2(n);i++)
        for(int j=2;j<=n;j++)
            table[j][i]=table[table[j][i-1]][i-1];

    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<=3;j++)cout<<table[i][j]<<' ';
    //         puts("");
    // }
    // cout<<lca(7,2);
    for(int i=1;i<=q;i++){
        scanf("%d %d",&x,&y);
        val=lca(x,y);
        val=depth[x]+depth[y]-2*depth[val];
        printf("%d\n",val);
    }

    
    
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); //file input.txt is opened in reading mode i.e "r"
    freopen("output.txt", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif
    solve();
}
