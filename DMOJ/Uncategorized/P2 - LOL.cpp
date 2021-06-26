#include <bits/stdc++.h>
using namespace std;

const int M1 = 1e3 + 5, M2 = -(1e3 + 5);

int N;
int min_x = M1, max_x = M2, min_y = M1, max_y = M2;

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);

  cin >> N;

  while(N--) {
    int X, Y;
    cin >> X >> Y;
    min_x = min(min_x, X);
    max_x = max(max_x, X);
    min_y = min(min_y, Y);
    max_y = max(max_y, Y);
  }

  cout << (max_x - min_x) * (max_y - min_y) << "\n";

  return 0;
}