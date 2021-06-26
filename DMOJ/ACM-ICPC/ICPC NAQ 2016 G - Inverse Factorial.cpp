#include <bits/stdc++.h>
using namespace std;

const int M1 = 6;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  string str;
  cin >> str;

  int factorial = 1;
  if(str.size() <= 6) {
    for(int ans = 1; ans < 10; ans++) {
      factorial *= ans;
      if(factorial == stoi(str)) {
        cout << ans << '\n';
        return 0;
      }
    }
  }

  double log_value = 0;
  for(int ans = 1; ; ans++) {
    log_value += log10(ans);
    if(floor(log_value) == str.size() - 1) {
      cout << ans << '\n';
      return 0;
    }
  }

  return 0;
}