#include <bits/stdc++.h>
using namespace std;
 
void solve() {
  int n;
  cin >> n;
  vector<int> s(n + 1);
  for(int i = 1; i <= n; i++) cin >> s[i];
 
  vector<int> dp(n + 1);
  int answer = 0;
  for(int i = n; i > 0; i--) {
    for(int j = 2 * i; j <= n; j += i) {
      if(s[j] > s[i]) dp[i] = max(dp[i], 1 + dp[j]);
    }
    answer = max(answer, 1 + dp[i]);
  }
  
  cout << answer << '\n';
}
 
int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int t;
  cin >> t;
  while(t--) solve();
 
  return 0;
}