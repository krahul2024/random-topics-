// custom comparators
// so what we do in custom comparators is change the default ascending 
// order of sorting by defining our own condition
// default condition is whether a<b?
#include<bits/stdc++.h>
using namespace std;
// ways to partition n into k groups
const int mod=1e9+7;
// sorting in descending order
bool compInt(int a,int b){
  return a>b;
}
// sorting a pair of elements on the basis of second element 
// in ascending order
bool compPair(pair<int,int>a,pair<int,int>b){
  // A comparator must return false for two equal objects (not doing so results in
  // undefined behavior and potentially a verdict of wrong answer or runtime error).
  if(a.second==b.second)return a.first<b.first;
  else return a.second<b.second;
}
// sorting in descending order on the basis of conditon 3x+7y of a pair 
// where x is first element of pair and y is second element of pair
bool compCond(pair<int,int>a,pair<int,int>b){
  return (3*a.first+a.second*7)>(3*b.first+b.second*7);
}
void solve(){
  int n;
  puts("enter the size of array");
  cin>>n;
  vector<pair<int,int>>a(n);
  puts("enter 10 pairs of elements or 20 elements");
  for(int i=0;i<n;i++)cin>>a[i].first>>a[i].second;
  sort(begin(a),end(a),compCond);
  puts("sorting in descending order on the basis of conditon 3x+7y of a pair where x is first element of pair and y is second element of pair");
  for(auto i:a)cout<<i.first<<" "<<i.second<<"\n";
}
int main(){
  solve();
}
