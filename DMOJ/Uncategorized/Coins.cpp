#include <bits/stdc++.h>
using namespace std;

const int M1 = 3e3 + 5;

int N;
double dp[M1][M1];

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);

  cin >> N;

  dp[0][0] = 1.0;
  for(int coin = 1; coin <= N; coin++) {
    double p;
    cin >> p;
    dp[coin][0] = 1.0;
    for(int amount = 1; amount < coin; amount++) {
      dp[coin][amount] = (p * dp[coin - 1][amount - 1]) + ((1.0 - p) * dp[coin - 1][amount]);
    }
    dp[coin][coin] = p * dp[coin - 1][coin - 1];
  }

  cout << setprecision(12) << fixed << dp[N][int(ceil(double(N / 2.0)))] << "\n";

  return 0;
}