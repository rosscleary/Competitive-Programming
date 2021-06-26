#include <bits/stdc++.h>
using namespace std;
 
#define LL long long
 
LL N, K;
LL result_1, result_2;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  cin >> N >> K;
 
  cout << min(N % K, K - (N % K)) << "\n";
 
  return 0;
}