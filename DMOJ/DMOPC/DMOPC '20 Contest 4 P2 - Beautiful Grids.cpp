#include <bits/stdc++.h>
using namespace std;

#define int long long
 
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, M, K;
  cin >> N >> M >> K;
  vector<pair<int, int>> ones(K);
  unordered_map<int, int> row_cnts, col_cnts;
  for(int i = 0; i < K; i++) {
    cin >> ones[i].first >> ones[i].second;
    row_cnts[ones[i].first]++, col_cnts[ones[i].second]++;
  }

  vector<int> row_odds, col_odds;
  for(auto i: row_cnts) {
    if(i.second & 1) {
      row_odds.push_back(i.first);
    }
  }
  for(auto i: col_cnts) {
    if(i.second & 1) {
      col_odds.push_back(i.first);
    }
  }

  vector<pair<int, int>> ans;
  for(int i = 0; i < min(row_odds.size(), col_odds.size()); i++) {
    ans.push_back({row_odds[i], col_odds[i]});
  }
  if(row_odds.size() > col_odds.size()) {
    for(int i = col_odds.size(); i < row_odds.size(); i++) {
      ans.push_back({row_odds[i], 1});
    }
  } else if(col_odds.size() > row_odds.size()) {
    for(int i = row_odds.size(); i < col_odds.size(); i++) {
      ans.push_back({1, col_odds[i]});
    }
  }

  cout << ans.size() << '\n';
  for(auto i: ans) {
    cout << i.first << ' ' << i.second << '\n';
  }

  return 0;
}