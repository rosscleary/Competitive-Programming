#include <bits/stdc++.h>
using namespace std;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int start, interval, send;
  cin >> start >> interval >> send;

  start += interval;
  for(int cnt = 0; cnt < 3; cnt++, start += interval) {
    if(start >= send) {
      cout << start << '\n';
      return 0;
    }
  }

  cout << "Who knows...\n";

  return 0;
}