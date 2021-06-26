#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n, x;
  cin >> n >> x;
  vector<int> left(n), right(n);
  for(int i = 0; i < n; i++) {
    cin >> left[i] >> right[i];
  }

  int ans = 0;
  for(int i = 0; i < n; i++) {
    if(left[i] <= x && right[i] >= x) {
      continue;
    }
    if(x < left[i]) {
      ans += left[i] - x;
      int right_i = left[i];
      for(int j = i + 1; j < n; j++) {
        if(right[j] < x) {
          break;
        } else if(left[j] > x) {
          if(left[j] < right_i) {
            x = left[j];
            right_i = min(right_i, right[j]);
          } else {
            x = right_i;
            break;
          }
        } else {
            right_i = min(right_i, right[j]);
        }
      }
    } else {
      ans += x - right[i];
      int left_i = right[i];
      for(int j = i + 1; j < n; j++) {
        if(left[j] > x) {
          break;
        } else if(right[j] < x) {
          if(right[j] > left_i) {
            x = right[j];
            left_i = max(left_i, left[j]);
          } else {
            x = left_i;
            break;
          }
        } else {
          left_i = max(left_i, left[j]);
        }
      }
    }
  }

  cout << ans << '\n';

  return 0;
}