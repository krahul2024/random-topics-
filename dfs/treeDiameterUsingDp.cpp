// ctrl+alt+f for formatting
//this method is based on storing largest and second largest depth of its child 
//for each node and then taking max of second best + best .
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 11, mod = 1e9 + 7;
#define pb push_back
#define all(x) begin(x),end(x)
vector<int>g[N],dp1(N,0),dp2(N,0),mark(N,0);
int f(int x){
    mark[x]=1;
    for(int i:g[x])
        if(!mark[i]){
            int k=f(i);
            if(dp1[x]<k)dp2[x]=dp1[x],dp1[x]=k;
            else if(dp2[x]<k)dp2[x]=k;
        }
    return dp1[x]+1;
}
void solve(){
    int n;
    scanf("%d",&n);
    int x,y;
    for(int i=1;i<n;i++){
        scanf("%d %d",&x,&y);
        g[x].pb(y);
        g[y].pb(x);
    }
    f(1);
    int mx=0;
    for(int i=1;i<=n;i++)mx=max(dp1[i]+dp2[i],mx);
    printf("%d\n",mx);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); //file input.txt is opened in reading mode i.e "r"
    freopen("output.txt", "w", stdout); //file output.txt is opened in writing mode i.e "w"
#endif
    solve();
}
