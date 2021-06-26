#include <bits/stdc++.h>
using namespace std;

const set<string> words = {"ook", "ookook", "oog", "ooga", "ug", "mook", "mookmook", "oogam", "oogum", "ugug"};

void solve() {
  string N;
  cin >> N;

  vector<int> dp(N.length() + 1);
  dp[N.length()] = 1;
  for(int i = N.length() - 1; i >= 0; i--) {
    string next = "";
    for(int j = i; j < N.length(); j++) {
      next += N[j];
      if(words.find(next) != words.end()) dp[i] += dp[j + 1];
    }
  }

  cout << dp[0] << '\n';
}
 
int main() { 
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int test_case = 10;
  while(test_case--) solve();

  return 0;
}