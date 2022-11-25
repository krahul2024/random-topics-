#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define pb push_back
#define int long long int
int cnt=0;
void solve() {
  int a,b,a1,b1,x,x0=0,x1=1,y=1;
  cin>>a>>b,a1=a,b1=b;
  vector<int>gcd;
  while(b>0)gcd.push_back(a/b),x=b,b=a%b,a=x;
  reverse(gcd.begin(),gcd.end());
  for(int i=1;i<gcd.size();i++)x1=y,y=x0-x1*gcd[i],x0=x1;
  cout<<a1<<"*x + "<<b1<<"*y = "<<a<<" => x="<<x1<<", y="<<y<<'\n';
  if(x1*a1+b1*y!=a)cnt++;
}

signed main() {
  long long t; scanf("%lld", &t); while (t--)solve();
    cout<<cnt<<" wrong answers.\n";
}
