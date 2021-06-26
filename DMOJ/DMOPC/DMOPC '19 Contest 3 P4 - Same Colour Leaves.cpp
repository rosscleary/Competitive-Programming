#include <bits/stdc++.h>
using namespace std;

#define int long long

const int M1 = 1e9 + 7;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;
  vector<char> colours(N + 1);
  for(int i = 1; i <= N; i++) {
    cin >> colours[i];
  }
  vector<vector<int>> adj(N + 1);
  for(int i = 0; i < N - 1; i++) {
    int u_i, v_i;
    cin >> u_i >> v_i;
    adj[u_i].push_back(v_i), adj[v_i].push_back(u_i);
  }

  queue<int> q;
  vector<int> dist(N + 1);
  vector<bool> vis(N + 1);
  q.push(1), vis[1] = true;
  while(!q.empty()) {
    int curr = q.front();
    q.pop();
    for(auto i: adj[curr]) {
      if(!vis[i]) {
        vis[i] = true, dist[i] = dist[curr] + 1, q.push(i);
      }
    }
  }

  map<int, vector<int>> degree_nodes;
  for(int i = 1; i <= N; i++) {
    degree_nodes[-dist[i]].push_back(i);
  }

  vector<vector<int>> dp(N + 1, vector<int>(2));
  int ans = 0;
  for(auto i: degree_nodes) {
    int degree = -i.first;
    vector<int> degree_list = i.second;
    for(auto i: degree_list) {
      dp[i][0] = 1, dp[i][1] = 1;
      int subtract_0 = 0, subtract_1 = 0;
      for(auto j: adj[i]) {
        if(dist[i] < dist[j]) {
          if(dp[i][0] == -1) {
            dp[i][0] = dp[j][0] + 1;
          } else {
            dp[i][0] *= dp[j][0] + 1;
          }
          dp[i][0] %= M1;
          if(dp[i][1] == -1) {
            dp[i][1] = dp[j][1] + 1;
          } else {
            dp[i][1] *= dp[j][1] + 1;
          }
          dp[i][1] %= M1;
          subtract_0 += dp[j][0], subtract_1 += dp[j][1];
          subtract_0 %= M1, subtract_1 %= M1;
        }
      }
      dp[i][0] -= (colours[i] != 'B'), dp[i][1] -= (colours[i] != 'R');
      dp[i][0] += M1, dp[i][0] %= M1, dp[i][1] += M1, dp[i][1] %= M1;
      ans += dp[i][0] + dp[i][1], ans %= M1;
      if(colours[i] == 'B') {
        ans -= subtract_1, ans += M1, ans %= M1;
      } else {
        ans -= subtract_0, ans += M1, ans %= M1;
      }
    }
  }

  cout << ans << '\n';

  return 0;
}