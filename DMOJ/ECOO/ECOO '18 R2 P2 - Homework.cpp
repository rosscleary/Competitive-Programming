#include <bits/stdc++.h>
using namespace std;

const int M1 = 1e6;

void solve() {
  int N;
  cin >> N;
  vector<pair<double, int>> D_W(N);
  for(int i = 0; i < N; i++) cin >> D_W[i].second >> D_W[i].first;

  set<int> days_available;
  for(int day = 1; day <= M1; day++) days_available.insert(-day);
  sort(D_W.begin(), D_W.end());
  double answer = 0;
  for(int i = N - 1; i >= 0; i--) {
    if(days_available.lower_bound(-D_W[i].second) == days_available.end()) continue;
    days_available.erase(days_available.lower_bound(-D_W[i].second));
    answer += D_W[i].first;
  }

  cout << setprecision(4) << fixed << answer << '\n';
}
 
int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int test_case = 10;
  while(test_case--) solve();
 
  return 0;
}