#include <stdio.h>
#include<iostream>
#include<sstream>// used for stringstream
#include<vector>
#include<climits.h>//used for infinity
#include<cstring>//used for memset
using namespace std;
#define int long long int
#define pb push_back

//taking unknown number of integer inputs in cpp
signed main()
{
  char s[1000];
  while (gets(s)) {
    stringstream sin(s);
    int a[100],n=0;
    while (sin >> a[n])n++;
    for(int i=0;i<n;i++)printf("%lld ",a[i]);
    	puts("");
  }
  return 0;
}
