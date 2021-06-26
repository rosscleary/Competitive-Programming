#include <bits/stdc++.h>
using namespace std;

const int M1 = 1e6 + 5, M2 = 0;

int P;
int min_x = M1, min_y = M1, max_x = M2, max_y = M2;

int main() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> P;

  for(int i = 0; i < P; i++) {
    int x, y; cin >> x >> y;
    min_x = min(min_x, x);
    min_y = min(min_y, y);
    max_x = max(max_x, x);
    max_y = max(max_y, y);
  }

  cout << 2 * (max_x - min_x + max_y - min_y) << '\n';

  return 0;
}