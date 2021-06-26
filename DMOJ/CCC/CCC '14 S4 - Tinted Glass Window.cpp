#include <bits/stdc++.h>
using namespace std;

#define int long long

struct rect {
  int x_l, y_t, x_r, y_b, t_i;
};

struct row_value {
  int i;
  bool open;
  int t_i;
};

bool sort_fun(row_value row_value_1, row_value row_value_2) {
  return row_value_1.i < row_value_2.i;
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, T;
  cin >> N >> T;
  vector<rect> rects(N);
  map<int, vector<row_value>> rows;
  for(int i = 0; i < N; i++) {
    cin >> rects[i].x_l >> rects[i].y_t >> rects[i].x_r >> rects[i].y_b >> rects[i].t_i;
    rows[rects[i].y_t] = {}, rows[rects[i].y_b] = {};
  }

  vector<int> rows_i;
  for(auto i: rows) {
    rows_i.push_back(i.first);
    for(int j = 0; j < N; j++) {
      if(rects[j].y_t <= i.first && rects[j].y_b > i.first) {
        row_value start, end;
        start.i = rects[j].x_l, start.open = true, start.t_i = rects[j].t_i;
        end.i = rects[j].x_r, end.open = false, end.t_i = rects[j].t_i;
        rows[i.first].push_back(start), rows[i.first].push_back(end);
      }
    }
    sort(rows[i.first].begin(), rows[i.first].end(), sort_fun);
  }
  
  sort(rows_i.begin(), rows_i.end());
  int ans = 0;
  for(int i = 0; i < rows_i.size() - 1; i++) {
    int curr_row = rows_i[i];
    int open_value = rows[curr_row][0].t_i;
    for(int j = 1; j < rows[curr_row].size(); j++) {
      if(open_value >= T) {
        ans += (rows[curr_row][j].i - rows[curr_row][j - 1].i) * (rows_i[i + 1] - curr_row);
      }
      if(rows[curr_row][j].open) {
        open_value += rows[curr_row][j].t_i;
      } else {
        open_value -= rows[curr_row][j].t_i;
      }
    }
  }

  cout << ans << '\n';

  return 0;
}