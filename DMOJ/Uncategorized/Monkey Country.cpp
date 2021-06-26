#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  int P, Q;
  cin >> P >> Q;
  vector<int> a(N);
  for(int i = 0; i < N; i++) {
    cin >> a[i];
  }

  vector<int> add(N);
  for(int i = 0; i < N; i++) {
    a[i] += add[i], a[i] %= MOD;
    cout << a[i] << ' ';
    int r = N - (N - i) * P / Q;
    if(r < N) {
      add[r] = 2 * a[i], add[r] %= MOD;
    }
  }
  cout << '\n';

  return 0;
}