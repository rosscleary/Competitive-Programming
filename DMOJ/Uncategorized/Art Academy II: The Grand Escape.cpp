#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, M;
  cin >> N >> M;
  vector<int> hashed_values;
  for(int i = 0; i < N; i++) {
    int v_i;
    cin >> v_i;
    int result = (v_i * 244002641) % 4294967296;
    if(result == 0) {
      hashed_values.push_back(4294967296);
    } else {
      hashed_values.push_back(result);
    }
  }

  sort(hashed_values.begin(), hashed_values.end());
  int ans = 0;
  for(int i = N - 1, left = M; left; i--, left--) {
    ans += hashed_values[i];
  }

  cout << ans << '\n';

  return 0;
}