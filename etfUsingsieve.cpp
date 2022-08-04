//this code is for counting coprimes in the range upto n<=9e6+1 and can answer q queries in over all 
// O(q) time
// overall time complexity is O(n*{loglog(n)-log(n)}+q)
// Success #stdin #stdout 0.92s 120560KB for n=1e7
// 4000000
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pss pair<string,string>
// #define int long long int
const int N=6e6+1;
int phi[N],spf[N];
vector<int>dp(N);
vector<int>a(N,1);
// function to compare whether two numbers are coprime or not
bool iscoprime(int a,int b){
	if(__gcd(a,b)==1)return true;
	else return false;
}
// this is mighty sieve using which we are using to calculate the spf array 
//spf array means that it contains smallest prime factor of all numbers in some range
// as we know that coprimes for a number if it is prime will be n-1;
// now let's see some facts about coprimes
// // let's call coprime of n as f(n)
// now see that if p is prime-> f(p)=p-1 , f(p^k)=(p^(k-1))(p-1) so if a number n=p1^k1*p2*k2*.......
// then we can say f(n)=((p1^(k1-1))(p1-1))*((p2^(k2-1))(p2-1))*...... which can be reduced to
// f(n)=(p1^k1-p1^(k1-1))*(p2^k2-p2^(k2-1))*....... which can further be reduced to f(n)=p1^k1*p2^k1*..(1-1/p1)*(1-1/p2)*....
// which gives us the formula f(n)=(n*(p1-1)*(p2-1)*...)/(p1*p2*...)
// one more thing is that if tow numbers are coprime then f(a*b)=f(a)*f(b) where f(n) is count of coprimes of n upto n
void sieve(int n){
	vector<bool>prime(n+1,1);
	prime[0]=prime[1]=0;
	for(int i=2;i<=n;i++){
		if(prime[i]){
			spf[i]=i;
			for(int j=i;j<=n;j+=i)spf[j]=i,prime[j]=0;
		}
	}
	phi[1]=1;
	cout<<1<<"\n";
}
// this method works in O(n*logn) or we can also make it work in O(q*logn)
void anotherMethod(int n){
	for(int i=1;i<=n;i++){
		int k=i,sp,sum=i;
		while(k>1){
			sp=spf[k];
			while(k%sp==0 and k>1)k/=sp;
			sum=((sum*(sp-1))/sp);
		}
		// cout<<"\n";
		cout<<sum<<"\n";
	}
}
//this one is also using sieve 
void oneMoreMethod(int n){
	for(int i=1;i<=n;i++)dp[i]=i;
	for(int i=2;i<=n;i++){
		if(dp[i]==i)
			for(int j=i;j<=n;j+=i)
				dp[j]-=dp[j]/i;// this step is basically n*(1-1/p1)*(1-1/p2).....
	}
	for(int i=1;i<=n;i++)cout<<dp[i]<<"\n";
}
// above methods are for queries but we can make second or anotherMethod(n) run for large numbers upto 10^9 by removing first for
// loop then we will be having time complexity O(√n). below is the code for same
void solve(){
	// freopen("citystate.in","r",stdin);
	// freopen("citystate.out","w",stdin);
	int n;
	cin>>n;
	sieve(n);
    //here i am calculating the count of coprimes 
	for(int i=2;i<=n;i++){
		int j=spf[i],k=i;
		if(j==i)phi[i]=i-1;//this is for primes where i=7 and spf[7]=j=7
		else if(iscoprime(i/j,j))phi[i]=phi[i/j]*phi[j];//this is for i=6 and spf[6]=j=2
		else if(i==j*j)phi[i]=phi[i]=phi[j]*j;//this is for case i=9 and spf[9]=j=3
		else phi[i]=phi[i/j]*j;// this is for case i=16 and spf[16]=j=2
		cout<<phi[i]<<"\n";
	}
	// cout<<phi[n];
}
int main() 
{
    solve();
}
