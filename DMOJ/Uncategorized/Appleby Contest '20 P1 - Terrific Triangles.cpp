#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while(T--) {
    vector<int> l(3);
    for(int i = 0; i < 3; i++) {
      cin >> l[i];
    }
    sort(l.begin(), l.end());
    int less_sum = l[0] * l[0] + l[1] * l[1];
    int hyp = l[2] * l[2];
    if(less_sum < hyp) {
      cout << 'O';
    } else if(less_sum == hyp) {
      cout << 'R';
    } else {
      cout << 'A';
    }
    cout << '\n';
  }

  return 0;
}