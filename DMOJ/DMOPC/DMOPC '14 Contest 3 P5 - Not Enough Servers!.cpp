#include <bits/stdc++.h>
using namespace std;

int M;
int fails;
vector<int> case_masks;
vector<pair<int, pair<int, int>>> dp;

pair<int, pair<int, int>> solve(int mask) {
  if(mask == 0) {
    return {0, {0, 0}};
  }
  if(dp[mask].first) {
    return dp[mask];
  }

  dp[mask].first = fails + 1;
  for(int j = 0; j < M; j++) {
    int new_mask = mask;
    for(int k = 0; k < fails; k++) {
      if((mask & (1 << k)) && (case_masks[j] & (1 << k))) {
        new_mask ^= (1 << k);
      }
    }
    pair<int, pair<int, int>> next = solve(new_mask);
    if(1 + next.first < dp[mask].first) {
      dp[mask].first = 1 + next.first;
      dp[mask].second.first = j;
      dp[mask].second.second = new_mask;
    }
  }

  return dp[mask];
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N >> M;
  vector<string> verdicts;
  for(int i = 0; i < N; i++) {
    string verdict;
    cin >> verdict;
    if(verdict.find('X') != -1) {
      verdicts.push_back(verdict);
    }
  }
  fails = verdicts.size();

  if(fails == 0) {
    cout << 1 << '\n' << 1 << '\n';
    return 0;
  }

  case_masks.resize(M);
  for(int i = 0; i < M; i++) {
    for(int j = 0; j < fails; j++) {
      if(verdicts[j][i] == 'X') {
        case_masks[i] |= (1 << j);
      }
    }
  }

  dp.resize(1 << fails);
  cout << solve((1 << fails) - 1).first << '\n';
  for(int i = (1 << fails) - 1; i > 0; i = dp[i].second.second) {
    cout << dp[i].second.first + 1 << ' ';
  }
  cout << '\n';

  return 0;
}