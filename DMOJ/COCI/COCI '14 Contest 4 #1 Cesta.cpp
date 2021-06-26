#include <bits/stdc++.h>
using namespace std;

int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  string N;
  cin >> N;

  vector<int> digit_freq(10);
  int digit_sum = 0;
  for(int i = 0; i < N.length(); i++) {
    digit_sum += N[i] - '0', digit_freq[N[i] - '0']++;
  }
  if(!digit_freq[0] || digit_sum % 3) {
    cout << -1 << '\n';
    return 0;
  }
  for(int i = 9; i >= 0; i--) {
    for(int j = 0; j < digit_freq[i]; j++) cout << i;
  }
  cout << '\n';

  return 0;
}