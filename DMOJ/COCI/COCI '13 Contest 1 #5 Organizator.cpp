#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  int max_team_size = 0;
  vector<int> team_size_freq(2e6 + 1);
  for(int i = 0; i < N; i++) {
    int team_size;
    cin >> team_size;
    max_team_size = max(max_team_size, team_size);
    team_size_freq[team_size]++;
  }

  int ans = 0;
  for(int i = 1; i <= 2e6; i++) {
    int valid_count = 0;
    for(int j = i; j <= max_team_size; j += i) valid_count += team_size_freq[j];
    if(valid_count > 1) ans = max(ans, i * valid_count);
  }
  cout << ans << '\n';

  return 0;
}