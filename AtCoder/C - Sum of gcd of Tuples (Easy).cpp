#include <bits/stdc++.h>
using namespace std;
 
#define LL long long
 
int K;
LL answer = 0;
 
int gcd(int a, int b, int c) {
  int gcd_value = 0;
  int max_value = max(a, max(b, c));
 
  for(int i = 1; i <= sqrt(max_value); i++) {
    if(a % i == 0 && b % i == 0 && c % i == 0) gcd_value = max(gcd_value, i);
    if(a % (max_value / i) == 0 && b % (max_value / i) == 0 && c % (max_value / i) == 0) gcd_value = max(gcd_value, max_value / i);
  }
 
  return gcd_value;
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  cin >> K;
 
  for(int i = 1; i <= K; i++) {
    for(int j = 1; j <= K; j++) {
      for(int k = 1; k <= K; k++) {
        answer += gcd(i, j, k);
      }
    }
  }
 
  cout << answer << "\n";
 
  return 0;
}