#include <bits/stdc++.h>
using namespace std;

#define int long long

const int M1 = 1e9 + 7;

int sum(int num) {
  int num_1 = num, num_2 = num + 1;
  if(num_1 % 2 == 0) {
    num_1 /= 2;
  } else {
    num_2 /= 2;
  }
  num_1 %= M1, num_2 %= M1;
  return (num_1 * num_2) % M1;
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  assert(N >= 1 && N <= 100000);
  vector<pair<int, int>> a_b(N);
  int chores_left = 0;
  for(int i = 0; i < N; i++) {
    cin >> a_b[i].first >> a_b[i].second;
    chores_left += a_b[i].second;
    assert(a_b[i].first >= 1 && a_b[i].first <= 1000000000 && a_b[i].second >= 1 && a_b[i].second <= 1000000000);
  }

  sort(a_b.begin(), a_b.end());
  int ans = 0;
  for(int i = 0; i < N; i++) {
    int multiply = (sum(chores_left) - sum(chores_left - a_b[i].second) + M1) % M1;
    ans += multiply * a_b[i].first, ans %= M1, chores_left -= a_b[i].second;
  }

  cout << ans << '\n';

  return 0;
}