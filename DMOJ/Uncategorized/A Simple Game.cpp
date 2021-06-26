#include <bits/stdc++.h>
using namespace std;

int N, Q; vector<int> a;
vector<pair<int, int>> prefix_max; vector<pair<int, int>> suffix_max;

int main() { 
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> N >> Q;
  a.resize(N);
  for(int i = 0; i < N; i++) cin >> a[i];

  prefix_max.resize(N);
  prefix_max[0].first = a[0]; prefix_max[0].second = 0;
  for(int i = 1; i < N; i++) {
    if(a[i] > prefix_max[i - 1].first) prefix_max[i].first = a[i], prefix_max[i].second = i;
    else prefix_max[i].first = prefix_max[i - 1].first, prefix_max[i].second = prefix_max[i - 1].second;
  }
  suffix_max.resize(N);
  suffix_max[N - 1].first = a[N - 1]; suffix_max[N - 1].second = N - 1;
  for(int i = N - 2; i >= 0; i--) {
    if(a[i] > suffix_max[i + 1].first) suffix_max[i].first = a[i], suffix_max[i].second = i;
    else suffix_max[i].first = suffix_max[i + 1].first, suffix_max[i].second = suffix_max[i + 1].second;
  }

  while(Q--) {
    int x; cin >> x, x--;
    cout << prefix_max[x - 1].second + 1 << ' ' << suffix_max[x + 1].second + 1 << '\n';
  }

  return 0;
}