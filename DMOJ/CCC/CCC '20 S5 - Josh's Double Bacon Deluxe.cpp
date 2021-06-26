#include <bits/stdc++.h>
using namespace std;

#define maxN 1000000
#define maxM 500000

double N;
double burger_values[maxN + 1];
double dp[maxM + 1];
bool dp_solved[maxM + 1];
double suffix_sum = 0.0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= int(N); i++) cin >> burger_values[i];

  if(burger_values[1] == burger_values[int(N)]) {
    cout << "1\n";
    return 0;
  }

  for(double person = N - 1.0; person >= 2.0; person--) {
    if(burger_values[int(person)] == burger_values[int(N)]) continue;
    if(burger_values[int(person)] == burger_values[1]) suffix_sum += 1.0;
    else if(dp_solved[int(burger_values[int(person)])]) suffix_sum += dp[int(burger_values[int(person)])];
    else {
      dp[int(burger_values[int(person)])] = (suffix_sum + 1.0) / (N - person + 1.0);
      dp_solved[int(burger_values[int(person)])] = true;
      suffix_sum += dp[int(burger_values[int(person)])];
    }
  }

  double answer = (suffix_sum + 1.0) / N;
  cout << setprecision(9) << fixed << answer << "\n";

  return 0;
}