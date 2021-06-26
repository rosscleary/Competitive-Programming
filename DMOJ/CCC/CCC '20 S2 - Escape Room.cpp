#include <bits/stdc++.h>
using namespace std;

const int maxM = 1e3 + 5, maxN = 1e3 + 5, maxvalue = 1e6 + 5;

int M, N;
vector<pair<int, int> > graph[maxvalue];
stack<pair<int, int> > q;
bool visited[maxN][maxM];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> M >> N;

  for (int i = 1; i <= M; i++) {
    for (int j = 1; j <= N; j++) {
      int value; cin >> value;
      graph[value].push_back(make_pair(i, j));
    }
  }

  q.push(make_pair(M, N));
  visited[M][N] = true;

  while (!q.empty()) {
    pair<int, int> curr = q.top();
    int product = curr.first * curr.second;
    q.pop();
    for (int i = 0; i < graph[product].size(); i++) {
      int row = graph[product][i].first, col = graph[product][i].second;
      if (!visited[row][col]) {
        if (row == 1 && col == 1) {
          cout << "yes\n";
          return 0;
        }
        q.push(make_pair(row, col));
        visited[row][col] = true;
      }
    }
  }

  cout << "no\n";

  return 0;
}