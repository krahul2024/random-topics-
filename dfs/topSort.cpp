//windows+v for past copied history
// scanf("%lld",&)
// int n;
//  in(n);
//  vector<int>a(n);
//  for(int i=0;i<n;i++)in(a[i]);
#include <iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<cstring>
#include<map>
#include<cmath>
#define pb push_back
#define in(k) scanf("%lld",&k)
#define inPair(l,r) scanf("%lld %lld",&l,&r)
#define out(k) printf("%lld",k)
#define all(a) begin(a),end(a)
#define int long long int
#define nl puts("")
#define cm printf(" ");
using namespace std;
const int mod = 1e9 + 7;

struct pr {
  int l, r;
} typedef pr;

const int N = 1e5 + 11;
vector<int>tSort;
vector<int>mark(N, 0), g[N];

// top sort is ordering of nodes in which is sorted as per appearance of of parent
void topSort(int x) {
  mark[x] = 1;
  for (auto i : g[x])if (!mark[i])topSort(i);
  tSort.pb(x);
}

void solve() {
  tSort.clear();
  mark.assign(N, 0);
  int n, m;
  inPair(n, m);
  int x, y;
  for (int i = 1; i <= m; i++) {
    inPair(x, y);
    g[x].pb(y);//top sort is only for acyclic graphs and directed graphs
  }
  for (int i = 1; i <= n; i++)if (!mark[i])topSort(i);
  reverse(all(tSort));
  for (auto i : tSort) {out(i); cm;};
}
signed main()
{
  solve();
}
