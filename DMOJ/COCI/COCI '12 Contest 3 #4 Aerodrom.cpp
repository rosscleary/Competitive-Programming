#include <bits/stdc++.h>
using namespace std;

#define int long long
 
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, M;
  cin >> N >> M;
  vector<int> T(N);
  for(int i = 0; i < N; i++) {
    cin >> T[i];
  }

  int lo = 0, hi = 1e18, ans = 1e18;
  while(lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    int remain = M;
    for(int i = 0; i < N; i++) {
      remain -= mid / T[i];
    }
    if(remain <= 0) {
      ans = min(ans, mid), hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }

  cout << ans << '\n';

  return 0;
}