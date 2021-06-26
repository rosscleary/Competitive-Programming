#include <bits/stdc++.h>
using namespace std;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int N, X, Y;
  cin >> N >> X >> Y;

  int round_cnt = 0;
  while(true) {
    round_cnt++;
    int range = Y - X - 1, guess = X + range / 2 + (range & 1);
    if(N > guess) {
      X = guess;
    } else if(N < guess) {
      Y = guess;
    } else {
      break;
    }
  }

  cout << round_cnt << '\n';

  return 0;
}