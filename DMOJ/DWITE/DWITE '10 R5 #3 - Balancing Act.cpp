#include <bits/stdc++.h>
using namespace std;

const int M1 = 3e1 + 5, M2 = 32e3;
const int M4 = 30e3;

int test_case = 5;
int N;
int dp[M1][M2];

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);

  while(test_case--) {
    cin >> N;

    for(int weight = 0; weight <= M4; weight++) {
      dp[0][weight] = weight;
    }

    for(int item = 1; item <= N; item++) {
      int W;
      cin >> W;
      for(int weight = 0; weight <= M4; weight++) {
        dp[item][weight] = min(dp[item - 1][weight + W], dp[item - 1][abs(weight - W)]);
      }
    }

    cout << dp[N][0] << "\n";
  }

  return 0;
}