#include <bits/stdc++.h>
using namespace std;

const int M1 = 2e2;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int n;
  cin >> n;

  vector<int> digits(M1);
  digits[M1 - 1] = 1;
  for(int num = 2; num <= n; num++) {
    vector<int> new_digits(M1);
    vector<int> add(M1);
    for(int i = M1 - 1; i > 1; i--) {
      new_digits[i] = (digits[i] * num + add[i]) % 10;
      add[i - 1] += ((digits[i] * num + add[i]) / 10) % 10;
      add[i - 2] += ((digits[i] * num + add[i]) / 100);
    }
    digits = new_digits;
  }

  int ans = 0;
  bool not_lead_zeroes = false;
  for(int i = 0; i < M1; i++) {
    not_lead_zeroes = not_lead_zeroes || digits[i] != 0;
    ans += not_lead_zeroes && digits[i] == 0;
  }

  cout << ans << '\n';

  return 0;
}