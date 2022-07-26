#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int M, N;
  cin >> M >> N;
  map<int, int> freq;
  for(int i = 0; i < M; i++) {
    int x;
    cin >> x;
    freq[x]++;
  }

  vector<pair<int, int>> freqs;
  for(auto i: freq) {
    freqs.push_back(i);
  }

  int prev, curr = 0;
  for(int i = freqs.size() - 1; i >= 0; i--) {
    curr += freqs[i].second;
    if(curr > N) {
      cout << prev << '\n';
      return 0;
    }
    prev = curr;
  }

  cout << curr << '\n';

  return 0;
}
