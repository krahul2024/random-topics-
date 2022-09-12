#include<bits/stdc++.h>
using namespace std;
const int N=2e5+111,mod=1e9+7;
#define pb push_back
#define all(x) begin(x),end(x)
vector<int>parent(N),sz(N,1);

void makeSet(int x){
  parent[x]=x;
  sz[x]=1;
}

int findSet(int x){
  if(x==parent[x]) return x;
  return parent[x]=findSet(parent[x]);
}

void unionSet (int x,int y){
  x=find(x),y=find(y);
    if(x!=y){
      // in this operation we check size of which set is greater and assign parent of greater
    // set as parent of smaller set which makes union of these two sets hence the swapping.
    if(sz[x]<sz[y])swap(x,y);
    parent[y]=x;
    sz[x]+=sz[y];
  }
  else return;
}
