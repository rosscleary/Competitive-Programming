#include <bits/stdc++.h>
using namespace std;

bool vowel(char c) {
  return c == 'A';
}

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  string seq;
  cin >> seq;

  cout << seq[0];
  for(int i = 1; i < seq.size(); i++) {
    if(vowel(seq[i]) == vowel(seq[i - 1])) {
      cout << ' ';
    }
    cout << seq[i];
  }
  cout << '\n';

  return 0;
}