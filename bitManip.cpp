// bit manipulation stuff
#include <bits/stdc++.h>
#define int long long int
#define pb push_back
#define fs(x) fastscan(x)
using namespace std;
//this is for fast scanning
void fastscan(long long &x)
    {
        bool neg=false;
        register long long  c;
        x =0;
        c=getchar();
        if(c=='-')
        {
            neg = true;
            c=getchar();
        }
        for(;(c>47 && c<58);c=getchar())
            x = (x<<1) + (x<<3) +c -48;
        if(neg)
            x *=-1;
    }
// to check if MSBs of two numbers are same or not?
bool isSame(int a,int b){
	int k=max(log2(a),log2(b));
	return (a&(1<<k) and b&(1<<k));
}
void solve(){
    int n=3;
    vector<int>a,c(n);
    a.pb(3),a.pb(4),a.pb(5);
    // for(int i=0;i<n;i++)fs(a[i]);
 //    this loop counts occurrences of all elements in all subarrays
	// like how many times a number appears in all subarrays the array
	// this can help in finding sum of all subarrays in O(n)
	// we just have to multiply respective array elements with their
	// couns and we get sum of all subarrays,this is also helpful in 
	// calculating XOR of all subarrays in just O(n) or O(n*logn)
    for(int i=0;i<n;i++)c[i]=((i+1)*(n-i)),cout<<a[i]<<" appears "<<c[i]<<" times\n";
    // all subarrays are (3),(4),(5),(3,4),(4,5),(3,4,5)

}
signed main() 
{
    solve();
}
