#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<int> days(N);
  for(int i = 0; i < N; i++) {
    cin >> days[i];
  }

  vector<bool> taken(N);
  int ans = 0;
  for(int i = 1; i < N; i++) {
    if(taken[i]) {
      continue;
    }
    ans++;
    int diff = days[i] - 1;
    int last = i;
    for(int j = i + 1; j < N; j++) {
      if(days[j] - days[last] == diff) {
        taken[j] = true;
        last = j;
      }
    }
  }

  cout << ans << '\n';

  return 0;
}