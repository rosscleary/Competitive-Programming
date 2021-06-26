#include <bits/stdc++.h>
using namespace std;

double P, Q, W;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> P >> Q >> W;
  Q -= 0.5;
  W /= 100.0;

  double answer = ((Q - ((1.0 - W) * P)) / W);
  answer = round(answer * 1000.0) / 1000.0;
  answer = ceil(answer);
  answer = max(0.0, answer);
  if(answer <= 100.0) cout << answer << "\n";
  else cout << "DROP THE COURSE\n";

  return 0;
}