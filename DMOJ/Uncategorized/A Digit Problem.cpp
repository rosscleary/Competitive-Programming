#include <bits/stdc++.h>
using namespace std;

const int M1 = 10, M2 = 1e9 + 7;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<int> a_i_index(M1, -1);
  for(int i = 0; i < N; i++) {
    int a_i;
    cin >> a_i;
    a_i_index[a_i] = i;
  }
  string K;
  cin >> K;
  int K_len = K.length();

  vector<vector<int>> dp_less(K_len + 1, vector<int>(1 << N)), dp_equal(K_len + 1, vector<int>(1 << N));
  dp_less[K_len][0] = 1, dp_equal[K_len][0] = 1;
  for(int i = K_len - 1; i > 0; i--) {
    for(int j = 0; j < 1 << N; j++) {
      for(int k = 0; k < M1; k++) {
        int next_j = j;
        if(a_i_index[k] != -1) {
          next_j &= ~(1 << a_i_index[k]);
        }
        dp_less[i][j] += dp_less[i + 1][next_j];
        dp_less[i][j] %= M2;
      }
      for(int k = 0; k <= K[i] - '0'; k++) {
        int next_j = j;
        if(a_i_index[k] != -1) {
          next_j &= ~(1 << a_i_index[k]);
        }
        if(k == K[i] - '0') {
          dp_equal[i][j] += dp_equal[i + 1][next_j];
        } else {
          dp_equal[i][j] += dp_less[i + 1][next_j];
        }
        dp_equal[i][j] %= M2;
      }
    }
  }

  int ans = 0;
  for(int i = 0; i < K_len; i++) {
    for(int j = 1; j < M1; j++) {
      if(i == 0 && j > K[i] - '0') {
        break;
      }
      int next_mask = (1 << N) - 1;
      if(a_i_index[j] != -1) {
        next_mask &= ~(1 << a_i_index[j]);
      }
      if(i == 0 && j == K[i] - '0') {
        ans += dp_equal[i + 1][next_mask];
      } else {
        ans += dp_less[i + 1][next_mask];
      }
      ans %= M2;
    }
  }

  if(N == 1 && a_i_index[0] != -1) ans++;
  cout << ans << '\n';

  return 0;
}