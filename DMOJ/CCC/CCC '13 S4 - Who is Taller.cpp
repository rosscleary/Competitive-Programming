#include <bits/stdc++.h>
using namespace std;

#define maxN 1000000

int N, M, p, q;
map<int,vector<int> > graph;

list<int> bfs_q;
bool visited[maxN + 1];

int bfs_result(int start, int end) {
  bfs_q.push_back(start);

  while (!bfs_q.empty()) {
    int curr = bfs_q.front();
    bfs_q.pop_front();
    for (int i = 0; i < graph[curr].size(); i++) {
      if (graph[curr][i] == end) {
        return true;
      }
      if (!visited[graph[curr][i]]) {
        bfs_q.push_back(graph[curr][i]);
        visited[graph[curr][i]] = true;
      }
    }
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  int x,y;
  while (M--) {
    cin >> x >> y;
    graph[x].push_back(y);
  }
  cin >> p >> q;

  if (bfs_result(p, q)) {
    cout << "yes" << endl;
  }
  else {
    bfs_q.clear();
    memset(visited, false, sizeof(visited));
    if (bfs_result(q, p)) {
      cout << "no" << endl;
    }
    else {
      cout << "unknown" << endl;
    }
  }

  return 0;
}