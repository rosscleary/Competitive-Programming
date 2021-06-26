#include <bits/stdc++.h>
using namespace std;

int X, Y, H, V, T;

void valid_entry(int x, int y) {
  if(x + y == 0 || x >= X + H || y >= Y + V) {
    return;
  }
  if((2 * x - y) % 3 == 0) {
    int right_moves = (2 * x - y) / 3;
    int up_moves = x - 2 * right_moves;
    if(right_moves >= 0 && up_moves >= 0 && right_moves + up_moves < T) {
      cout << "YES\n";
      exit(0);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> X >> Y >> H >> V >> T;

  for(int x = X; x < X + H; x++) {
    valid_entry(x, Y);
  }
  for(int y = Y; y < Y + V; y++) {
    valid_entry(X, y);
  }

  cout << "NO\n";

  return 0;
}