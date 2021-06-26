#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int M1 = 1e5 + 5;
const int MOD = 1e9 + 7;

string K;

LL dp[M1][2][2][2];
bool dp_solved[M1][2][2][2];

LL solve(int index, bool under, bool one, bool one_zero) {
  if(index == K.length() - 1) {
    if(!one) return 0;
    if(!one_zero) return 1;
    if(under) return 9;
    return K[index] - '0';
  }
  if(dp_solved[index][under][one][one_zero]) return dp[index][under][one][one_zero];

  if(under) {
    for(int i = 0; i < 10; i++) {
      if(i == 0) {
        if(one_zero) continue;
        else if(one) dp[index][under][one][one_zero] += solve(index + 1, under, one, true);
        else dp[index][under][one][one_zero] += solve(index + 1, under, one, one_zero);
        continue;
      }
      if(i == 1) {
        dp[index][under][one][one_zero] += solve(index + 1, under, true, one_zero);
        continue;
      }
      dp[index][under][one][one_zero] += solve(index + 1, under, one, one_zero);
    }
  } else {
    for(int i = 0; i < K[index] - '0'; i++) {
      if(i == 0) {
        if(one_zero) continue;
        else if(one) dp[index][under][one][one_zero] += solve(index + 1, true, one, true);
        else dp[index][under][one][one_zero] += solve(index + 1, true, one, one_zero);
        continue;
      }
      if(i == 1) {
        dp[index][under][one][one_zero] += solve(index + 1, true, true, one_zero);
        continue;
      }
      dp[index][under][one][one_zero] += solve(index + 1, true, one, one_zero);
    }
    if(K[index] - '0' == 0) {
      if(one && !one_zero) dp[index][under][one][one_zero] += solve(index + 1, under, one, true) ;
      if(!one && !one_zero) dp[index][under][one][one_zero] += solve(index + 1, under, one, one_zero);
      dp[index][under][one][one_zero] %= MOD;
    } else if(K[index] - '0' == 1) dp[index][under][one][one_zero] += solve(index + 1, under, true, one_zero) % MOD;
      else dp[index][under][one][one_zero] += solve(index + 1, under, one, one_zero) % MOD;
  }

  dp[index][under][one][one_zero] %= MOD;
  dp_solved[index][under][one][one_zero] = true;
  return dp[index][under][one][one_zero];
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);

  cin >> K;

  cout << solve(0, false, false, false) << "\n";

  return 0;
}