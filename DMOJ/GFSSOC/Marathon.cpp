#include <bits/stdc++.h>
using namespace std;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, Q;
  cin >> N >> Q;
  vector<int> prefix_sum(N + 1);
  for(int i = 1; i <= N; i++) {
    int k_i;
    cin >> k_i;
    prefix_sum[i] = prefix_sum[i - 1] + k_i;
  }

  for(int i = 0; i < Q; i++) {
    int a_i, b_i;
    cin >> a_i >> b_i;
    cout << prefix_sum[N] - (prefix_sum[b_i] - prefix_sum[a_i - 1]) << '\n';
  }

  return 0;
}