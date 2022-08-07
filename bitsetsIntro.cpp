//bitsets //
// don't run it else you will be stormed by errors
// we can represent set of larger sizes in the form of bitsets
// bitsets support and,or,xor and shift operations also counting set bits
// using name.count() all these operations in O(1)
// we can create bitsets of size upto 10^9 without any problem
#include <bits/stdc++.h>
using namespace std;
const int N=1e9+1;
bitset<N>a;
//this gives binary representation of a number 179851111111 in 32 bit
    // bitset<32>a(179851111111);
bitset<N>dp;
void knapsack(){
  int n=4;
  int a[n]={2,4,5,7},sum=11;
  // this problem can be solved using boolean dp array of max_weight like below
  // this solution works in N*W
  bool dp[max_weight+1];
  in this first for loop we check for each value of the array for sum={a[i],sum}
  in second for loop we check if there exists a value currentSum-a[i] then we mark that 
  we can form currentSum too which is j
  for(int i=0;i<n;i++)for(int j=sum;j>=a[i];j--)if(dp[j-a[i]])dp[j]=1;
  cout<<dp[sum]<<"\n";
  
  // now using bitsets we can solve the same problem in N*(W/32)
  // let's consider 000000000000 representing sum upto 0-11 obviously we can mark (a[i]:i->{0,n-1}=)1,but let's leave as while checking 
  // whether mark[sum-a[i]]? when sum=a[i] and mark[0]=1 will lead to mark[sum-a[i]]=1;
  // now our dp is 100000000000 as sum=0 can always be true ,so dp[0]=1 now lets's say we are checking for first number a[0]=2,
  // here we see that first number or 0th bit is set means we can form sum=0 so if a[i]=2 then we can also form 0+a[i]->0+2
  // ,now to make dp[a[i]]=1,we shift dp by a[i] places so after shifting it will look like 001000000000, and now we can take or of this with dp
  // before shifting 100000000000 OR 001000000000 -> 101000000000 same thing we go on doing for rest of the numbers and in the last 
  // we print dp[sum]?
  // code is like this
  dp[0]=1;
  for(int i=0;i<n;i++)dp|=(dp<<a[i]);
  cout<<dp[sum]<<"\n";
  
  
  // CREDITS:- Errichto video on bitsets watch following video
  //   https://www.youtube.com/watch?v=jqJ5s077OKo
}
void solve(){
  int n;
  cin>>n;int x;
  // let's say the n=5 numbers are 12,121,121,111,1111111111
  for(int i=0;i<n;i++)cin>>x,a[x]=1;
  // gives number of set bits which is a.count()=4
  cout<<a.count()<<"\n";
}
int main() 
{
    solve();
}
