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
  bool keep_going=true;
  while (keep_going) {
    int n;
    cin>>n;
    if (n==0) {
      keep_going=false;
      break;
    }
    int numbers[201];
    for (int i=1; i<=n; i++) {
      cin>>numbers[i];
    }
    long long dp[201][199]={0};
    for (int base_case=2; base_case<=n-1; base_case++) {
      dp[base_case][1]=numbers[base_case-1]+numbers[base_case]+numbers[base_case+1];
    }
    for (int length=1; length<=n-2; length++) {
      for (int start_index=2; start_index<=(n-1)-(length-1); start_index++) {
        for (int last_pick=start_index; last_pick<=start_index+(length-1); last_pick++) {
          int result=dp[start_index][last_pick-start_index]+dp[last_pick+1][(start_index+(length-1))-last_pick]+numbers[last_pick]+numbers[start_index-1]+numbers[start_index+length];
          if (result>dp[start_index][length]) {
            dp[start_index][length]=result;
          }
        }
      }
    }
    cout<<dp[2][n-2]<<endl;
  }
}