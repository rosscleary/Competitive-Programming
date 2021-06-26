#include <bits/stdc++.h>
using namespace std;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, K;
  cin >> N >> K;
  vector<int> h(N);
  int max_h_i = 0;
  for(int i = 0; i < N; i++) {
    cin >> h[i];
    max_h_i = max(max_h_i, h[i]);
  }

  vector<int> ans(max_h_i + 1);
  for(int i = 0; i < N; i++) {
    if(h[i] <= K) continue;
    for(int j = K; j <= max_h_i; j += h[i]) ans[j]++;
  }

  for(int i = 0; i < N; i++) {
    cout << ans[h[i]] - (K == 0 ? 1 : 0) << ' ';
  }
  cout << '\n';

  return 0;
}