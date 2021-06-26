#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> adj;
vector<double> dp;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> N >> M;
  adj.resize(N + 1);
  for(int i = 0; i < M; i++) {
    int lake_i, lake_j; cin >> lake_i >> lake_j;
    if(lake_i < lake_j) adj[lake_i].push_back(lake_j);
  }

  dp.resize(N + 1);
  dp[1] = 1.0;
  for(int lake = 1; lake <= N; lake++) {
    for(int i = 0; i < adj[lake].size(); i++) dp[adj[lake][i]] += dp[lake] / double(adj[lake].size());
  }

  for(int i = 1; i <= N; i++) {
    if(adj[i].size() == 0) cout << setprecision(12) << fixed << dp[i] << '\n';
  }

  return 0;
}