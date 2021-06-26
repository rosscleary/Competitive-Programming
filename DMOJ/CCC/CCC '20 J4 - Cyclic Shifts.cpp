#include <bits/stdc++.h>
using namespace std;

string T, S;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T >> S;

  for (int i = 0; i < T.length(); i++) {
    if (T.find(S) != -1) {
      cout << "yes\n";
      return 0;
    }
    S += S[0];
    S.erase(0, 1);
  }

  cout << "no\n";

  return 0;
}