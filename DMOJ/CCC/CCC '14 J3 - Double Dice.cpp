#include <bits/stdc++.h>
using namespace std;

int n;
int score_1 = 100, score_2 = 100;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  while(n--) {
    int roll_1, roll_2; cin >> roll_1 >> roll_2;
    score_1 -= (roll_1 < roll_2) * roll_2;
    score_2 -= (roll_2 < roll_1) * roll_1;
  }

  cout << score_1 << "\n" << score_2 << "\n";

  return 0;
}