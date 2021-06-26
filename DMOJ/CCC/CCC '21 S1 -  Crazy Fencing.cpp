#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<int> h(N + 1), w(N);
  for(int i = 0; i < N + 1; i++) {
    cin >> h[i];
  }
  for(int i = 0; i < N; i++) {
    cin >> w[i];
  }

  int ans = 0, rem = 0;
  for(int i = 0; i < N; i++) {
    ans += ((h[i] + h[i + 1]) * w[i]) / 2;
    if(((h[i] + h[i + 1]) * w[i]) % 2 == 1) {
      rem++;
    }
  }

  ans += rem / 2;
  cout << ans;
  if(rem % 2 == 1) {
    cout << ".5";
  }
  cout << '\n';

  return 0;
}