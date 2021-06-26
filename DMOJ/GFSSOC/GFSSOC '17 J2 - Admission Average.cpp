#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int mark, aif_score, requirement;
  int sum = 0;

  for (int i = 0; i < 6; i++) {
    cin >> mark;
    sum += mark;
  }

  cin >> aif_score;

  cin >> requirement;

  sum / 6 + aif_score >= requirement ? cout << "yes" << endl : cout << "no" << endl;

  return 0;
}