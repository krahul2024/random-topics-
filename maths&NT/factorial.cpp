#include<bits/stdc++.h>
using namespace std;
void solve() {
  int n, rem = 0, x = 0, k, i;
  cout << "Enter the number (should be less than 3000) you want to find factorial of :";
  cin >> n;
  vector<int>a(9300, 0);
  //setting the last digit to one
  a[a.size() - 1] = 1;
  for (i = 1; i <= n; i++) {
    k = a.size() - 1, rem = 0;
    //doing multiplication and updating the next values by adding remainder to them
    while (k >= 0)x = a[k] * i + rem, a[k] = x % 10, rem = x / 10, k--;
  }
  i = 0;
  while (!a[i])i++;
  cout << "\nFactorial of the number " << n << " is :\n";
  for (; i < a.size(); i++)cout << a[i];
  cout << '\n';
}
int32_t main() {
  int t=1;
  while(t){
    solve();
    char c;
    cout<<"Enter y if you want to continue :";
    cin>>c and c=='y'?t=1:t--;
  }
  // solve();
}
