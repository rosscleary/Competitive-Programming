#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <iomanip>
using namespace std;

int n, entry_fees[1001];
int dp[1001][1001];

int min_cost(int,int);

int main () {

  cin>>n;

  for (int i=1; i<=n; i++) {
    cin>>entry_fees[i];
  }

  cout<<min_cost(2,1)+entry_fees[2]<<endl;

  return 0;

}

int min_cost(int square, int last_length) {

   if (dp[square][last_length]) {
     return dp[square][last_length];
   }

  if (square==n) {
    return 0;
  }

  int option_1=1000000000;
  int option_2=1000000000;
  if (square+last_length+1<=n) {
    option_1=entry_fees[square+last_length+1]+min_cost(square+last_length+1,last_length+1);
  }
  if (square-last_length>=1) {
    option_2=entry_fees[square-last_length]+min_cost(square-last_length,last_length);
  }

  return dp[square][last_length]=min(option_1,option_2);

}