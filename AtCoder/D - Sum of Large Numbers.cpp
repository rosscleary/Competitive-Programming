#include <bits/stdc++.h>
using namespace std;
 
#define ULL unsigned long long
 
const int MOD = 1e9 + 7;
 
ULL N, K;
ULL all_sum;
ULL answer = 0;
 
int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);
 
  cin >> N >> K;
 
  all_sum = ((N * (N + 1)) / 2);
  for(ULL take = K; take <= N; take++) {
    ULL greatest = all_sum - (((N - take) * (N - take + 1)) / 2);
    ULL smallest = (take * (take - 1)) / 2;
    answer += greatest - smallest + 1;
    answer %= MOD;
  }
  answer++;
 
  cout << answer % MOD << "\n";
 
  return 0;
}