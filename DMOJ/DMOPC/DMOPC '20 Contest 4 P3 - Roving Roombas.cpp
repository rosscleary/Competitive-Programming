#include <bits/stdc++.h>
using namespace std;

#define int long long

int M;
vector<int> bit;

void update(int i) {
  for(; i <= M; i += i & -i) {
    bit[i]++;
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

  int N;
  cin >> N >> M;
  vector<pair<int, int>> roombas(N), cleaners(M + 1);
  for(int i = 0; i < N; i++) {
    cin >> roombas[i].second >> roombas[i].first;
  }
  for(int i = 1; i <= M; i++) {
    cin >> cleaners[i].first >> cleaners[i].second;
  } 
  vector<pair<int, int>> cleaner_list;
  sort(cleaners.begin(), cleaners.end());
  for(int i = 1; i <= M; i++) {
    cleaner_list.push_back({cleaners[i].second, i});
  }

  sort(roombas.begin(), roombas.end()), sort(cleaner_list.begin(), cleaner_list.end());
  bit.resize(M + 1);
  int ans = 0;
  int pointer = M - 1;
  for(int i = roombas.size() - 1; i >= 0; i--) {
    while(pointer >= 0 && cleaner_list[pointer].first >= roombas[i].first) {
      update(cleaner_list[pointer].second), pointer--;
    }
    int lo = 1, hi = M;
    int j = 0;
    while(lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if(cleaners[mid].first <= roombas[i].second) {
        j = max(j, mid), lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
    ans += query(j);
  }

  cout << ans << '\n';

  return 0;
}