#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, X;
  cin >> N >> X;
  multiset<int> call_cnts;
  while(N--) {
    int M_i;
    cin >> M_i;
    call_cnts.insert(-M_i);
  }

  int ans = 0;
  for(int take = 0; take < X && *call_cnts.begin() < 0; take++) {
    int curr = *call_cnts.begin();
    ans += -curr, call_cnts.erase(call_cnts.find(curr)), call_cnts.insert(curr + 1);
  }

  cout << ans << '\n';

  return 0;
}