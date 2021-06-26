#include <bits/stdc++.h>
using namespace std;

const int MAX_LENGTH = 55, MAX_LETTER = 30;
const string alph("_abcdefghijklmnopqrstuvwxyz");

string s;
int length;
int dp[MAX_LENGTH][MAX_LETTER];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s;
  length = s.length() - 1;

  for(int i = length; i >= 0; i--) {
    int current_letter = alph.find(s[i]);
    for(int last = 0; last < 27; last++) {
      if(current_letter <= last) dp[i][last] = dp[i + 1][last];
      else dp[i][last] = max(dp[i + 1][last], 1 + dp[i + 1][current_letter]);
    }
  }
  cout << 26 - dp[0][0] << "\n";

  return 0;
}