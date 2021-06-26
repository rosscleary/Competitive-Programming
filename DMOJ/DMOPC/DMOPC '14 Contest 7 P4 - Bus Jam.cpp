#include <bits/stdc++.h>
using namespace std;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, M, H;
  cin >> N >> M >> H;
  vector<int> T(N);
  for(int i = 0; i < N; i++) cin >> T[i];

  int total_wait = 0, answer = 0;
  for(int i = N - 2; i >= 0; i--) {
    int curr_wait = max(0, (total_wait + (T[i + 1] - T[i])) - H);
    int num_breaks = ceil(1.0 * curr_wait / M);
    total_wait = num_breaks * M;
    answer += num_breaks;
  }

  cout << answer << '\n';

  return 0;
}