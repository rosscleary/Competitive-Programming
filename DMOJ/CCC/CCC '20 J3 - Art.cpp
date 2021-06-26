#include <bits/stdc++.h>
using namespace std;

const int max_value = 1e2 + 5, min_value = -1;

int N;
int max_x = min_value, min_x = max_value, max_y = min_value, min_y = max_value;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  while(N--) {
    int x, y; char comma; cin >> x >> comma >> y;

    max_x = max(max_x, x); 
    min_x = min(min_x, x);
    max_y = max(max_y, y);
    min_y = min(min_y, y);
  }

  cout << min_x - 1 << "," << min_y - 1 << "\n";
  cout << max_x + 1 << "," << max_y + 1 << "\n";

  return 0;
}