#include <bits/stdc++.h>
using namespace std;

const int M1 = 2e3 + 5;

int N;
map<string, bool> is_word;

int test_case = 10;
string words;
int dp[M1];

int main() { ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> N;
  for(int i = 0; i < N; i++) {
    string word; cin >> word;
    is_word[word] = true;
  }

  while(test_case--) {
    cin >> words;

    dp[words.length()] = 0;
    for(int i = words.length() - 1; i >= 0; i--) {
      dp[i] = M1;
      string take = "";
      for(int j = i; j < words.length(); j++) {
        take += words[j];
        if(is_word.count(take)) dp[i] = min(dp[i], 1 + dp[j + 1]);
      }
    }

    cout << dp[0] - 1 << '\n';
  }

  return 0;
}