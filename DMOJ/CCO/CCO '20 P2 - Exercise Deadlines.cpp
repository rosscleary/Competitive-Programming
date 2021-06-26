#include <bits/stdc++.h>
using namespace std;

#define int long long

int N;
vector<int> bit;

void add(int i) {
  for(; i <= N; i += i & -i) {
    bit[i]++;
  }
}

void remove(int i) {
  for(; i <= N; i += i & -i) {
    bit[i]--;
  }
}

int query(int i) {
  int ans = 0;
  for(; i > 0; i -= i & -i) {
    ans += bit[i];
  }
  return ans;
}
 
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> N;
  vector<int> d(N + 1);
  unordered_map<int, vector<int>> d_locations;
  for(int i = 1; i <= N; i++) {
    cin >> d[i];
    d_locations[d[i]].push_back(i);
  }

  bit.resize(N + 1);
  for(int i = 1; i <= N; i++) {
    add(i);
  }
  int ans = 0;
  set<int> options;
  for(int i = N; i > 0; i--) {
    for(auto j: d_locations[i]) {
      options.insert(j);
    }
    if(options.empty()) {
      cout << "-1\n";
      return 0;
    }
    int take = *options.rbegin();
    ans += query(N) - query(take), options.erase(options.find(take)), remove(take);
  }

  cout << ans << '\n';

  return 0;
}