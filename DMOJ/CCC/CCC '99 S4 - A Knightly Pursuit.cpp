#include <bits/stdc++.h>
using namespace std;

int r, c;
queue<pair<int, int>> q;
vector<vector<int>> dist;
vector<vector<bool>> seen;

void add_next(int last_i, int last_j, int i, int j) {
  if(i > 0 && i <= r && j > 0 && j <= c && !seen[i][j]) {
    q.push({i, j});
    dist[i][j] = dist[last_i][last_j] + 1;
    seen[i][j] = true;
  }
}

void bfs(pair<int, int> start) {
  dist.clear(), dist.resize(r + 1, vector<int>(c + 1));
  for(int i = 1; i <= r; i++) {
    for(int j = 1; j <= c; j++) {
      dist[i][j] = -1;
    }
  }
  seen.clear(), seen.resize(r + 1, vector<bool>(c + 1));
  q.push(start), dist[start.first][start.second] = 0, seen[start.first][start.second] = true;

  while(!q.empty()) {
    pair<int, int> curr = q.front();
    q.pop();
    int i = curr.first, j = curr.second;
    add_next(i, j, i + 1, j - 2);
    add_next(i, j, i + 1, j + 2);
    add_next(i, j, i - 1, j - 2);
    add_next(i, j, i - 1, j + 2);
    add_next(i, j, i + 2, j - 1);
    add_next(i, j, i + 2, j + 1);
    add_next(i, j, i - 2, j - 1);
    add_next(i, j, i - 2, j + 1);
  }
}

void solve_tc() {
  int pr, pc, kr, kc;
  cin >> r >> c >> pr >> pc >> kr >> kc;

  bfs({kr, kc});
  int move = 0;
  int best_win = -1, best_stalemate = -1;
  for(; pr <= r; pr++, move++) {
    if(dist[pr][pc] != -1) {
      if(pr != r && move >= dist[pr][pc] && (move - dist[pr][pc]) % 2 == 0 && best_win == -1) {
        best_win = move;
      }
      if(move - 1 >= dist[pr][pc] && (move - 1 - dist[pr][pc]) % 2 == 0 && best_stalemate == -1) {
        best_stalemate = move - 1;
      }
    }
  }

  if(best_win != -1) {
    cout << "Win in " << best_win;
  } else if(best_stalemate != -1) {
    cout << "Stalemate in " << best_stalemate;
  } else {
    cout << "Loss in " << move - 2;
  }
  cout << " knight move(s).\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  while(n--) {
    solve_tc();
  }

  return 0;
}