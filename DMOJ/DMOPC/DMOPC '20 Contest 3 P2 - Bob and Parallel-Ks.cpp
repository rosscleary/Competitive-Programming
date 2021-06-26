#include <bits/stdc++.h>
using namespace std;

#define int long long

const int M1 = 1e17 + 7, M2 = 1e9 + 1;

int hash_value(int num_1, int num_2) {
  return ((num_1 * M2) % M1 + num_2) % M1;
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int M, N, K;
  cin >> M >> N >> K;
  vector<vector<int>> a(M, vector<int>(N));
  for(int i = 0; i < M; i++) {
    for(int j = 0; j < N; j++) {
      cin >> a[i][j];
    }
  }

  int ans = 0;
  for(int i = 0; i < N - 1; i++) {
    unordered_map<int, int> pair_cnt;
    pair_cnt[hash_value(a[0][i], a[0][i + 1])] = 1;
    for(int j = 1; j < M; j++) {
      if(a[j][i] > K && a[j][i + 1] > K && pair_cnt.count(hash_value(a[j][i] - K, a[j][i + 1] - K))) {
        ans += pair_cnt[hash_value(a[j][i] - K, a[j][i + 1] - K)];
      }
      if(pair_cnt.count(hash_value(a[j][i] + K, a[j][i + 1] + K))) {
        ans += pair_cnt[hash_value(a[j][i] + K, a[j][i + 1] + K)];
      }
      pair_cnt[hash_value(a[j][i], a[j][i + 1])]++;
    }
  }

  cout << ans << '\n';

  return 0;
}