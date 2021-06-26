#include <bits/stdc++.h>
using namespace std;

const int M1 = 4e3 + 1;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, T;
  cin >> N >> T;
  vector<int> locs(N);
  for(int i = 0; i < N; i++) {
    cin >> locs[i];
  }
  locs.push_back(0);
  sort(locs.begin(), locs.end());

  int ans = M1;
  for(int i = 0; i <= N && locs[i] <= 0; i++) {
    int next = i + T;
    if(next <= N && locs[next] >= 0) {
      ans = min(ans, abs(locs[i]) + locs[next] + min(abs(locs[i]), locs[next]));
    }
  }

  cout << ans << '\n';

  return 0;
}