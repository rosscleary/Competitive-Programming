#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<int> S(N);
  for(int i = 0; i < N; i++) {
    cin >> S[i];
  }

  vector<int> prefix_min(N), suffix_min(N);
  int last = S[0];
  for(int i = 1; i < N; i++) {
    if(S[i] >= last) {
      last = S[i];
      prefix_min[i] = prefix_min[i - 1];
    } else {
      prefix_min[i] = prefix_min[i - 1] + (last - S[i]);
    }
  }
  last = S[N - 1];
  for(int i = N - 2; i >= 0; i--) {
    if(S[i] >= last) {
      last = S[i];
      suffix_min[i] = suffix_min[i + 1];
    } else {
      suffix_min[i] = suffix_min[i + 1] + (last - S[i]);
    }
  }

  int ans = suffix_min[0];
  for(int i = 0; i < N; i++) {
    int curr = prefix_min[i];
    if(i != N - 1) {
      curr += suffix_min[i + 1];
    }
    ans = min(ans, curr);
  }

  cout << ans << '\n';

  return 0;
}