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
  string k;
  int d;
  cin>>k>>d;
  vector < vector<int> > dp(d,vector <int> (2));
  dp[0][0]=1;
  for (int digit_place=0; digit_place<k.length(); digit_place++) {
    vector < vector<int> > new_dp(d,vector <int> (2));
    for (int mod_d=0; mod_d<d; mod_d++) {
      for (int new_digit=0; new_digit<=k[digit_place]-'0'; new_digit++) {
        if (new_digit==k[digit_place]-'0') {
          new_dp[(mod_d+new_digit)%d][0]+=dp[mod_d][0];
          new_dp[(mod_d+new_digit)%d][0]=new_dp[(mod_d+new_digit)%d][0]%1000000007;
        }
        else {
          new_dp[(mod_d+new_digit)%d][1]+=dp[mod_d][0];
          new_dp[(mod_d+new_digit)%d][1]=new_dp[(mod_d+new_digit)%d][1]%1000000007;
        }
      }
      for (int new_digit=0; new_digit<=9; new_digit++) {
        new_dp[(mod_d+new_digit)%d][1]+=dp[mod_d][1];
        new_dp[(mod_d+new_digit)%d][1]=new_dp[(mod_d+new_digit)%d][1]%1000000007;
      }
    }
    dp=new_dp;
  }
  int answer=dp[0][0]+dp[0][1]-1;
  cout<<answer<<endl;
}