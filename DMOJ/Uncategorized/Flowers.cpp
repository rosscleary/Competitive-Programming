#include <bits/stdc++.h>
using namespace std;

#define int long long

int N;
vector<int> bit;

int query(int i) {
  int ans = 0;
  for(; i > 0; i -= i & -i) {
    ans = max(ans, bit[i]);
  }

  return ans;
}

void update(int i, int value) {
  for(; i <= N; i += i & -i) {
    bit[i] = max(bit[i], value);
  }
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> N;
  vector<int> h(N), a(N);
  for(int i = 0; i < N; i++) {
    cin >> h[i];
  }
  for(int i = 0; i < N; i++) {
    cin >> a[i];
  }

  bit.resize(N + 1);
  int ans = 0;
  for(int i = N - 1; i >= 0; i--) {
    int dp = a[i] + query(N - h[i] + 1);
    update(N - h[i] + 1, dp);
    ans = max(ans, dp);
  }
  
  cout << ans << '\n';

  return 0;
}