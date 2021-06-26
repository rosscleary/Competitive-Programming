#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, Q;
  cin >> N >> Q;
  unordered_map<int, int> freq;
  while(N--) {
    int a_i;
    cin >> a_i;
    freq[a_i]++;
  }

  while(Q--) {
    int type;
    cin >> type;
    if(type == 1) {
      int x;
      cin >> x;
      freq[x / 2] += freq[x], freq[(x + 1) / 2] += freq[x];
      freq[x] = 0;
    } else {
      int y;
      cin >> y;
      cout << freq[y] << '\n';
    }
  }

  return 0;
}