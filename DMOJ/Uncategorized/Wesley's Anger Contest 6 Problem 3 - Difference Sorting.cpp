#include <bits/stdc++.h>
using namespace std;

#define int long long

const int M1 = 1e18;

int N;
vector<int> a;
vector<pair<int, int>> sorted_a;

bool possible(int check) {
  vector<int> group(N);
  int curr_group = 1;
  group[sorted_a[0].second] = 1;
  for(int i = 1; i < N; i++) {
    if(sorted_a[i].first - sorted_a[i - 1].first > check) {
      curr_group++;
    }
    group[sorted_a[i].second] = curr_group;
  }

  for(int i = 0; i < N; i++) {
    if(group[i] != group[sorted_a[i].second]) {
      return false;
    }
  }

  return true;
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> N;
  a.resize(N), sorted_a.resize(N);
  for(int i = 0; i < N; i++) {
    cin >> a[i];
    sorted_a[i] = {a[i], i};
  }
  
  sort(sorted_a.begin(), sorted_a.end());

  int ans = M1 + 1;
  int l = 0, r = M1;
  while(l <= r) {
    int mid = l + (r - l) / 2;
    if(possible(mid)) {
      ans = min(ans, mid);
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  cout << ans << '\n';

  return 0;
}