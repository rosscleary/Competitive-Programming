#include <bits/stdc++.h>
using namespace std;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, K;
  cin >> N >> K;
  vector<double> a(N + 1);
  for(int i = 1; i <= N; i++) {
    cin >> a[i];
  }

  double left = 0, right = 1e6;
  while(right - left >= 0.000001) {
    double mid = (left + right) / 2.0;

    vector<double> ave_a = a;
    for(int i = 1; i <= N; i++) {
      ave_a[i] -= mid;
    }
    vector<double> prefix_sum(N + 1), prefix_min(N + 1);
    for(int i = 1; i <= N; i++) {
      prefix_sum[i] = prefix_sum[i - 1] + ave_a[i];
      prefix_min[i] = min(prefix_min[i - 1], prefix_sum[i]);
    }
    bool possible = false;
    for(int i = K; i <= N; i++) {
      if(prefix_sum[i] - prefix_min[i - K] >= 0) {
        possible = true;
        break;
      }
    }

    if(possible) {
      left = mid;
    } else {
      right = mid;
    }
  }

  cout << setprecision(9) << fixed << (left + right) / 2.0 << '\n';

  return 0;
}