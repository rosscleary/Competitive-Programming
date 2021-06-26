#include <bits/stdc++.h>
using namespace std;
 
#define LL long long
 
const int MAX_N = (2 * 1e5) + 5;
 
int N, A[MAX_N];
LL dp[MAX_N][4];
bool dp_solved[MAX_N][4];
LL answer;
 
LL solve(int index, int skips) {
  if(index < 0) return 0;
  if(index == 0) return A[0];
 
  if(dp_solved[index][skips]) return dp[index][skips];
 
  if(skips == 0) dp[index][skips] = A[index] + solve(index - 2, 0);
  if(skips == 1) dp[index][skips] = A[index] + max(solve(index - 2, 1), solve(index - 3, 0));
  if(skips == 2) dp[index][skips] = A[index] + max(solve(index - 2, 2), max(solve(index - 3, 1), solve(index - 4, 0)));
 
  dp_solved[index][skips] = true;
  return dp[index][skips];
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];
 
  if(N % 2 == 0) answer = max(solve(N - 1, 1), solve(N - 2, 0));
  else answer = max(solve(N - 1, 2), max(solve(N - 2, 1), solve(N - 3, 0)));
 
  cout << answer << "\n";
 
  return 0;
}