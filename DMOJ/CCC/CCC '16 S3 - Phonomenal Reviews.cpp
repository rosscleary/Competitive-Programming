#include <bits/stdc++.h>
using namespace std;

int N;
vector<set<int>> adj;

pair<int, int> longest_path(int start) {
  queue<int> q;
  vector<bool> seen(N);
  vector<int> dist(N);
  q.push(start);
  seen[start] = true;
  while(!q.empty()) {
    int curr = q.front();
    q.pop();
    set<int>::iterator it;
    for(it = adj[curr].begin(); it != adj[curr].end(); it++) {
      int next = *it;
      if(!seen[next]) {
        dist[next] = dist[curr] + 1;
        q.push(next);
        seen[next] = true;
      }
    }
  }

  int longest_path = 0, longest_i;
  for(int i = 0; i < N; i++) {
    if(dist[i] > longest_path) {
      longest_path = dist[i];
      longest_i = i;
    }
  }

  return {longest_path, longest_i};
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int M;
  cin >> N >> M;
  vector<int> is_restaurant(N);
  int start;
  for(int i = 0; i < M; i++) {
    int restaurant_i;
    cin >> restaurant_i;
    start = restaurant_i;
    is_restaurant[restaurant_i] = true;
  }

  adj.resize(N);
  for(int i = 0; i < N - 1; i++) {
    int a_i, b_i;
    cin >> a_i >> b_i;
    adj[a_i].insert(b_i);
    adj[b_i].insert(a_i);
  }

  queue<int> q;
  for(int i = 0; i < N; i++) {
    if(adj[i].size() == 1 && !is_restaurant[i]) {
      q.push(i);
    }
  }
  while(!q.empty()) {
    int curr = q.front();
    q.pop();
    set<int>::iterator it;
    for(it = adj[curr].begin(); it != adj[curr].end(); it++) {
      int next = *it;
      adj[next].erase(adj[next].find(curr));
      if(adj[next].size() == 1 && !is_restaurant[next]) {
        q.push(next);
      }
    }
    adj[curr].clear();
  }

  int num_paths = 0;
  for(int i = 0; i < N; i++) {
    num_paths += adj[i].size();
  }
  int next_start = longest_path(start).second;
  int tree_diameter = longest_path(next_start).first;
  cout << num_paths - tree_diameter << '\n';

  return 0;
}