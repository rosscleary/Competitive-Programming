#include <bits/stdc++.h>
using namespace std;

void solve_tc() {
  int s;
  cin >> s;
  vector<pair<int, int>> scores_recorded(s);
  for(int i = 0; i < s; i++) {
    char dash;
    cin >> scores_recorded[i].first >> dash >> scores_recorded[i].second;
    if(scores_recorded[i].first < scores_recorded[i].second) {
      swap(scores_recorded[i].first, scores_recorded[i].second);
    }
  }

  sort(scores_recorded.begin(), scores_recorded.end());
  vector<bool> score_counted(s);
  int m = 0;
  vector<vector<pair<int, int>>> ans(s);
  for(int i = 0; i < s; i++) {
    if(score_counted[i]) {
      continue;
    }
    int last_game_score = i;
    ans[m].push_back(scores_recorded[i]);
    for(int j = i + 1; j < s; j++) {
      if(score_counted[j]) {
        continue;
      }
      if(scores_recorded[j].first >= scores_recorded[last_game_score].first && scores_recorded[j].second >= scores_recorded[last_game_score].second) {
        score_counted[j] = true;
        ans[m].push_back(scores_recorded[j]);
        last_game_score = j;
      }
    }
    m++;
  }

  cout << m << '\n';
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j].first << '-' << ans[i][j].second << ' ';
    }
    cout << '\n';
  }
}

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  while(n--) {
    solve_tc();
  }

  return 0;
}