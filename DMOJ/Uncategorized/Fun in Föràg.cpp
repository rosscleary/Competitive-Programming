#include <bits/stdc++.h>
using namespace std;

#define int long long

struct edge {
  int b, c, input;
};

const int M1 = 1e11;

int N;
vector<vector<edge>> adj;
int A, B, C;

bool possible(int choice) {
  set<pair<int, int>> q;
  vector<int> dist(N + 1);
  q.insert({0, A});
  for(int i = 1; i <= N; i++) {
    dist[i] = M1;
  }
  dist[A] = 0;
  
  vector<int> best(N + 1);
  for(int i = 1; i <= N; i++) {
    best[i] = M1;
  }
  while(!q.empty()) {
    auto curr = *q.begin();
    q.erase(q.begin());
    if(dist[B] < C) {
      return true;
    }
    if(curr.first >= best[curr.second]) {
      continue;
    }
    best[curr.second] = curr.first;
    for(auto i: adj[curr.second]) {
      int next_dist = dist[curr.second] + i.c;
      if(i.input <= choice && next_dist < dist[i.b] && next_dist < C) {
        dist[i.b] = dist[curr.second] + i.c;
        q.insert({dist[i.b], i.b});
      }
    }
  }

  return dist[B] < C;
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int M;
  cin >> N >> M;
  adj.resize(N + 1);
  for(int i = 1; i <= M; i++) {
    int a_i, b_i, c_i;
    cin >> a_i >> b_i >> c_i;
    adj[a_i].push_back({b_i, c_i, i}), adj[b_i].push_back({a_i, c_i, i});
  }
  cin >> A >> B >> C;

  int l = 0, r = M;
  int ans = -1;
  while(l <= r) {
    int mid = l + (r - l) / 2;
    if(possible(mid)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  cout << ans << '\n';

  return 0;
}