#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(8);

int in_degree(int i) {
  int in_degree_cnt = 0;
  for(int j = 1; j <= 7; j++) {
    for(int k = 0; k < adj[j].size(); k++) {
      if(adj[j][k] == i) {
        in_degree_cnt++;
      }
    }
  }

  return in_degree_cnt;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  adj[1].push_back(7);
  adj[1].push_back(4);
  adj[2].push_back(1);
  adj[3].push_back(4);
  adj[3].push_back(5);

  while(true) {
    int x, y;
    cin >> x >> y;
    if(x == 0 && y == 0) {
      break;
    }
    adj[x].push_back(y);
  }

  set<int> pq;
  for(int i = 1; i <= 7; i++) {
    if(in_degree(i) == 0) {
      pq.insert(i);
    }
  }

  vector<int> ans;
  while(!pq.empty()) {
    int curr = *pq.begin();
    ans.push_back(curr);
    pq.erase(pq.begin());
    for(int i = 0; i < adj[curr].size(); i++) {
      if(in_degree(adj[curr][i]) == 1) {
        pq.insert(adj[curr][i]);
      }
    }
    adj[curr].clear();
  }

  for(int i = 1; i <= 7; i++) {
    if(in_degree(i) > 0) {
      cout << "Cannot complete these tasks. Going to bed.\n";
      return 0;
    }
  }

  for(int i: ans) {
    cout << i << ' ';
  }
  cout << '\n';

  return 0;
}