#include <bits/stdc++.h>
using namespace std;

struct edge {
  int b, t, h;
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int K, N, M;
  cin >> K >> N >> M;
  vector<vector<edge>> adj(N + 1);
  for(int i = 0; i < M; i++) {
    int a_i, b_i, t_i, h_i;
    cin >> a_i >> b_i >> t_i >> h_i;
    edge edge_i_a;
    edge_i_a.b = b_i, edge_i_a.t = t_i, edge_i_a.h = h_i;
    edge edge_i_b;
    edge_i_b.b = a_i, edge_i_b.t = t_i, edge_i_b.h = h_i;
    adj[a_i].push_back(edge_i_a);
    adj[b_i].push_back(edge_i_b);
  }
  int A, B;
  cin >> A >> B;

  vector<vector<int>> dist(N + 1, vector<int>(K + 1));
  set<pair<int, int>> q;
  for(int i = 1; i <= N; i++) {
    for(int j = 0; j <= K; j++) {
      dist[i][j] = 1e9;
    }
  }
  dist[A][0] = 0;
  q.insert({0, A});
  while(!q.empty()) {
    int curr = q.begin()->second;
    q.erase(q.begin());
    for(edge i: adj[curr]) {
      for(int j = 0; j + i.h < K; j++) {
        int option = dist[curr][j] + i.t;
        if(option < dist[i.b][j + i.h]) {
          dist[i.b][j + i.h] = option;
          q.insert({option, i.b});
        }
      }
    }
  }

  int ans = 1e9;
  for(int i = 0; i < K; i++) {
    ans = min(ans, dist[B][i]);
  }
  if(ans == 1e9) {
    cout << "-1\n";
  } else {
    cout << ans << '\n';
  }

  return 0;
}