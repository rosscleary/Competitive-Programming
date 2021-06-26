#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
vector<int> bit;

void update_bit(int value) {
  while(value <= 2 * N) {
    bit[value]++;
    value += value& - value;
  }
}

int prefix_freq(int value) {
  ll ans = 0;
  while(value > 0) {
    ans += bit[value];
    value -= value& - value;
  }
  return ans;
}

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> N;

  int prefix_sum = 0;
  bit.resize(2 * N + 1);
  update_bit(N);
  ll ans = 0;
  for(int i = 0; i < N; i++) {
    int v_i;
    cin >> v_i;
    prefix_sum += v_i == 1 ? 1 : -1;
    ans += prefix_freq(prefix_sum - 1 + N);
    update_bit(prefix_sum + N);
  }
  cout << ans << '\n';

  return 0;
}