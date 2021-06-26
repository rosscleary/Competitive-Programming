#include <bits/stdc++.h>
using namespace std;

#define int long long

const int M1 = 32;

void solve_tc() {
  int N;
  cin >> N;

  int ans = N;
  int one_cnt = 0;
  for(int i = 1; i <= M1; i++) {
    if(N & (1 << (i - 1))) {
      one_cnt++;
      ans -= (1 << (i - 1));
    }
    if(!(N & (1 << i)) && (N & (1 << (i - 1)))) {
      ans += 1 << i;
      break;
    }
  }
  for(int i = 0; i < one_cnt - 1; i++) {
    ans += (1 << i);
  }

  cout << ans << '\n';
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int test_case = 5;
  while(test_case--) {
    solve_tc();
  }

  return 0;
}