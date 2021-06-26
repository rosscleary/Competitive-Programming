#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<int> a(N);
  for(int i = 0; i < N; i++) cin >> a[i];

  vector<ll> dp(N + 2);
  for(int i = N - 1; i >= 0; i--) dp[i] = max(a[i] + dp[i + 2], dp[i + 1]);
  
  cout << dp[0] << '\n';

  return 0;
}