#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200001];
int in_degree[200001];

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N;
  cin >> N;

  set<pair<int, int>> next_node;
  for(int i = 1; i <= N; i++) {
    int C_i;
    cin >> C_i;
    in_degree[i] = C_i;
    next_node.insert({C_i, i});
    for(int j = 0; j < C_i; j++) {
      int value;
      cin >> value;
      adj[value].push_back(i);
    }
  }
  
  
  while(next_node.size()) {
    pair<int, int> search = *next_node.begin();
    next_node.erase(next_node.begin());
    int curr = search.second;
    cout << curr << ' ';
    for(auto next: adj[curr]) {
      next_node.erase(next_node.find({in_degree[next], next}));
      in_degree[next]--;
      next_node.insert({in_degree[next], next});
    }
  }
  cout << '\n';

  return 0;
}