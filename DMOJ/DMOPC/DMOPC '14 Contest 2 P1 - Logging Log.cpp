#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int D;

  cin >> D;

  for (int i = 1; i <= D; i++) {
    int T;
    cin >> T;
    int total_amount = 0;
    for (int j = 0; j < T; j++) {
      int amount;
      cin >> amount;
      total_amount += amount;
    }
    total_amount != 0 ? cout << "Day " << i << ": " << total_amount << endl : cout << "Weekend" << endl;
  }

  return 0;
}