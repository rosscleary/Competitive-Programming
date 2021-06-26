#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <string.h>
#include <iomanip>
using namespace std;

int main () {
  int n;
  cin>>n;
  char grid[2006][2006];
  for (int row=1; row<=n; row++) {
    for (int col=1; col<=n; col++) {
      cin>>grid[row][col];
    }
  }
  int dp[2006][2006]={0};
  int answer=0;
  for (int row=n; row>=1; row--) {
    for (int col=1; col<=n; col++) {
      if (grid[row][col]=='#') {
        dp[row][col]=1+min(min(dp[row+1][col-1],dp[row+1][col]),dp[row+1][col+1]);
      }
      else {
        dp[row][col]=0;
      }
      answer+=dp[row][col];
    }
  }
  cout<<answer<<endl;
}