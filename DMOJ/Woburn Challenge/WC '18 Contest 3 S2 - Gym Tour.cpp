#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> needed;

void needed_dfs(int curr, int last) {
  for(auto i: adj[curr]) {
    if(i != last) {
      needed_dfs(i, curr);
      needed[curr] = needed[curr] || needed[i];
    }
  }
}

int pruned_dfs(int curr, int last) {
  int ans = 0;
  for(auto i: adj[curr]) {
    if(i != last && needed[i]) {
      ans += 1 + pruned_dfs(i, curr);
    }
  }

  return ans;
}

int max_dist_dfs(int curr, int last) {
  int ans = 0;
  for(auto i: adj[curr]) {
    if(i != last && needed[i]) {
      ans = max(ans, 1 + max_dist_dfs(i, curr));
    }
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, K, F;
  cin >> N >> K >> F;
  needed.resize(N + 1);
  for(int i = 0; i < K; i++) {
    int G_i;
    cin >> G_i;
    needed[G_i] = true;
  }
  adj.resize(N + 1);
  for(int i = 0; i < N - 1; i++) {
    int A_i, B_i;
    cin >> A_i >> B_i;
    adj[A_i].push_back(B_i), adj[B_i].push_back(A_i);
  }

  needed_dfs(1, -1);
  int ans = pruned_dfs(1, -1) * 2 - max_dist_dfs(1, -1);
  needed[F] = true, needed_dfs(1, -1);
  ans = min(ans, pruned_dfs(1, -1));

  cout << ans << '\n';

  return 0;
}