#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int MAX_n = (3 * 1e5) + 5, MAX_VALUE = (3 * 10e17) + 100;
 
int T;
int n, a[MAX_n], b[MAX_n];
int answer;
 
int max(int a, int b) {
  if(a > b) return a;
  return b;
}
 
int min(int a, int b) {
  if(a < b) return a;
  return b;
}
 
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  scanf("%lld", &T);
 
  while(T--) {
    answer = MAX_VALUE;
 
    scanf("%lld", &n);
    int dp[n];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; i++) scanf("%lld%lld", &a[i], &b[i]);
 
    if(n == 1) {
      printf("%lld\n", a[0]);
    }
    else {
 
    dp[n - 1] = max(0, a[n - 1] - b[n - 2]);
    for(int i = n - 2; i > 0; i--) dp[i] = max(0, a[i] - b[i - 1]) +  dp[i + 1];
    dp[0] = max(0, a[0] - b[n - 1]) + dp[1];
 
    answer = a[0] + dp[1];
    answer = min(answer, a[n - 1] + dp[0] - dp[n - 1]);
 
    for(int i = 1; i < n - 1; i++) {
      answer = min(answer, a[i] + dp[i + 1] + (dp[0] - dp[i]));
    }
 
    printf("%lld\n", answer);
    }
  }
 
  return 0;
}