#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> edges(M);
  vector<vector<bool>> edge_exists(N + 1, vector<bool>(N + 1));
  for(int i = 0; i < M; i++) {
    cin >> edges[i].first >> edges[i].second;
    if(edges[i].first > edges[i].second) {
      swap(edges[i].first, edges[i].second);
    }
    edge_exists[edges[i].first][edges[i].second] = true;
  }

  set<set<int>> best_ans;
  set<set<int>> better_ans;
  for(int i = 0; i < M - 1; i++) {
    for(int j = i + 1; j < M; j++) {
      set<int> curr;
      curr.insert(edges[i].first), curr.insert(edges[i].second), curr.insert(edges[j].first), curr.insert(edges[j].second);
      if(curr.size() == 4) {
        best_ans.insert(curr);
        set<set<int>> new_best_ans;
        new_best_ans.insert(*best_ans.begin());
        best_ans = new_best_ans;
      } else if(curr.size() == 3) {
        vector<int> nodes;
        for(auto k: curr) {
          nodes.push_back(k);
        }
        for(int k = 0; k < 2; k++) {
          for(int l = k + 1; l < 3; l++) {
            pair<int, int> curr_edge = {nodes[k], nodes[l]};
            if(curr_edge != edges[i] && curr_edge != edges[j] && edge_exists[curr_edge.first][curr_edge.second]) {
              better_ans.insert(curr);
              set<set<int>> new_better_ans;
              new_better_ans.insert(*better_ans.begin());
              better_ans = new_better_ans;
            } 
          }
        }
      }
    }
  }

  if(better_ans.size() != 0) {
    cout << "3\n";
    for(auto i: *better_ans.begin()) {
      cout << i << ' ';
    }
  } else if(best_ans.size() != 0) {
    cout << "4\n";
    for(auto i: *best_ans.begin()) {
      cout << i << ' ';
    }
  } else {
    cout << -1;
  }
  cout << '\n';

  return 0;
}