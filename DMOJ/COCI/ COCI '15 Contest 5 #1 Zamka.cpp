#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int L, D, X;
  cin >> L >> D >> X;

  for(int i = L; i <= D; i++) {
    int num = i, sum = 0;
    while(num) {
      sum += num % 10;
      num /= 10;
    }
    if(sum == X) {
      cout << i << '\n';
      break;
    }
  }

  for(int i = D; i >= L; i--) {
    int num = i, sum = 0;
    while(num) {
      sum += num % 10;
      num /= 10;
    }
    if(sum == X) {
      cout << i << '\n';
      break;
    }
  }
  
	return 0;
}