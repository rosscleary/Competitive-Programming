#include <bits/stdc++.h>
using namespace std;

int x = -1, y = -5;
char curr_move;
int amount;
map<pair<int, int>, bool> point_visited;
bool safe = true;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  point_visited[make_pair(0, -1)] = true;
  point_visited[make_pair(0, -2)] = true;
  point_visited[make_pair(0, -3)] = true;
  point_visited[make_pair(1, -3)] = true;
  point_visited[make_pair(2, -3)] = true;
  point_visited[make_pair(3, -3)] = true;
  point_visited[make_pair(3, -4)] = true;
  point_visited[make_pair(3, -5)] = true;
  point_visited[make_pair(4, -5)] = true;
  point_visited[make_pair(5, -5)] = true;
  point_visited[make_pair(5, -4)] = true;
  point_visited[make_pair(5, -3)] = true;
  point_visited[make_pair(6, -3)] = true;
  point_visited[make_pair(7, -3)] = true;
  point_visited[make_pair(7, -4)] = true;
  point_visited[make_pair(7, -5)] = true;
  point_visited[make_pair(7, -6)] = true;
  point_visited[make_pair(7, -7)] = true;
  point_visited[make_pair(6, -7)] = true;
  point_visited[make_pair(5, -7)] = true;
  point_visited[make_pair(4, -7)] = true;
  point_visited[make_pair(3, -7)] = true;
  point_visited[make_pair(2, -7)] = true;
  point_visited[make_pair(1, -7)] = true;
  point_visited[make_pair(0, -7)] = true;
  point_visited[make_pair(-1, -7)] = true;
  point_visited[make_pair(-1, -6)] = true;
  point_visited[make_pair(-1, -5)] = true;

  while (true) {
    cin >> curr_move >> amount;
    if (curr_move == 'q') {
      break;
    }
    if (curr_move == 'd') {
      for (; amount > 0; amount--) {
        y--;
        if (point_visited[make_pair(x, y)]) {
          safe = false;
        }
        point_visited[make_pair(x, y)] = true;
      }
    } else if (curr_move == 'u') {
        for (; amount > 0; amount--) {
          y++;
          if (point_visited[make_pair(x, y)]) {
            safe = false;
          }
          point_visited[make_pair(x, y)] = true;
        }
    } else if (curr_move == 'l') {
        for (;amount > 0; amount--) {
          x--;
          if (point_visited[make_pair(x, y)]) {
            safe = false;
          }
          point_visited[make_pair(x, y)] = true;
        }
    } else {
        for (; amount > 0; amount--) {
          x++;
          if (point_visited[make_pair(x, y)]) {
            safe = false;
          }
          point_visited[make_pair(x, y)] = true;
        }
    }
    cout << x << " " << y << " ";
    if (safe) {
      cout << "safe\n";
    }
    else {
      cout << "DANGER\n";
      return 0;
    }
  }

  return 0;
}