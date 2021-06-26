#include <bits/stdc++.h>
using namespace std;

#define int long long

const int M1 = 1e16;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, C, K;
  cin >> N >> C >> K;
  vector<int> v(N + 1);
  for(int i = 1; i <= N; i++) {
    cin >> v[i];
  }
  vector<vector<int>> class_list(C + 1);
  vector<vector<int>> adj(N + 1);
  for(int i = 1; i <= N; i++) {
    int c_i;
    cin >> c_i;
    for(int j = 0; j < c_i; j++) {
      int class_num;
      cin >> class_num;
      adj[i].push_back(class_num), class_list[class_num].push_back(i);
    }
  }

  set<pair<int, int>> q;
  vector<int> dist(N + 1);
  vector<bool> searched(N + 1);
  for(int i = 1; i <= N; i++) {
    dist[i] = M1;
  }
  q.insert({0, 1}), dist[1] = 0;
  while(!q.empty()) {
    int curr = q.begin()->second;
    q.erase(q.begin());
    if(searched[curr]) {
      continue;
    }
    searched[curr] = true;
    for(auto i: adj[curr]) {
      for(auto j: class_list[i]) {
        if(dist[curr] + abs(v[curr] - v[j]) + K < dist[j]) {
          dist[j] = dist[curr] + abs(v[curr] - v[j]) + K;
          q.insert({dist[j], j});
        }
      }
    }
  }

  for(int i = 1; i <= N; i++) {
    cout << (dist[i] == M1 ? -1 : dist[i]) << '\n';
  }

  return 0;
}