#include <bits/stdc++.h>
using namespace std;

int N, french_values[100000], english_values[100000];

int dp[100000][3];

int main() 

{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;

  for (int i = 0; i < N; i++)
    cin >> french_values[i];

  for (int i = 0; i < N; i++)
    cin >> english_values[i];

  dp[0][0] = max(english_values[0], french_values[0]);
  dp[0][1] = max(english_values[0], french_values[0]);
  dp[0][2] = english_values[0];

  for (int word = 1; word < N; word++)
  {
    dp[word][0] = max(french_values[word] + dp[word - 1][1], english_values[word] + dp[word - 1][0]);
    dp[word][1] = max(french_values[word] + dp[word - 1][2], english_values[word] + dp[word - 1][0]);
    dp[word][2] = english_values[word] + dp[word - 1][0];
  }

  cout << dp[N - 1][0] << "\n";

  return 0;

}