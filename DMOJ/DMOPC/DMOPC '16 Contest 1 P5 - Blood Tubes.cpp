#include <bits/stdc++.h>
using namespace std;

#define int long long

int N;
vector<int> bit;

void update(int value) {
  for(; value <= N; value += value & - value) {
    bit[value]++;
  }
}

int query(int value) {
  int ans = 0;
  for(; value > 0; value -= value & - value) {
    ans += bit[value];
  }

  return ans;
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> N;
  bit.resize(N + 1);
  int ans = 0;
  for(int i = 0; i < N; i++) {
    int p_i;
    cin >> p_i;
    int query_value = query(p_i);
    ans += min(query_value, i - query_value);
    update(p_i);
  }

  cout << ans << '\n';

  return 0;
}