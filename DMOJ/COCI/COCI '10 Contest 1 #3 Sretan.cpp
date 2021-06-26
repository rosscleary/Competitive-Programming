#include <bits/stdc++.h>
using namespace std;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int K;
  cin >> K;

  int ans_length = 1, range;
  for(int amount_curr = 2, amount_total = 2; ; ans_length++, amount_curr *= 2, amount_total += amount_curr) {
    if(K <= amount_total) {
      range = amount_curr;
      K -= amount_total - amount_curr;
      break;
    }
  }

  for(int i = 1; i <= ans_length; i++) {
    range /= 2;
    if(K > range) {
      cout << 7;
      K -= range;
    } else {
      cout << 4;
    }
  }
  cout << '\n';

  return 0;
}