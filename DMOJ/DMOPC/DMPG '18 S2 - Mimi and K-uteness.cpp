#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;

  vector<int> prefix_sum(N + 1);
  for(int i = 1; i <= N; i++) {
    int A_i;
    cin >> A_i;
    prefix_sum[i] = prefix_sum[i - 1] + A_i;
  }
  int last = prefix_sum[N];
  cout << last << '\n';
  for(int k = 2; k <= N; k++) {
    last += prefix_sum[N] - prefix_sum[k - 1];
    last -= prefix_sum[N] - prefix_sum[N - k + 1];
    cout << last << '\n';
  }

  // 1 2 3 4 5

  // 1. 1+2+3+4+5 = 15
  // 2. (1+2)+(2+3)+(3+4)+(4+5) = 24 // 2 3 4
  // 3. (1+2+3)+(2+3+4)+(3+4+5) = 27 // 3
  // 4. (1+2+3+4)+(2+3+4+5) = 24 // 
  // 5. (1+2+3+4+5) = 15

  return 0;
}