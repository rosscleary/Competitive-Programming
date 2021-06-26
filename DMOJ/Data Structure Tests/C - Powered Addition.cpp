#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int MAX_n = 1e5 + 5;
 
int t;
int n, a[MAX_n];
int max_diff;
 
int min_time(int diff) {
  if(diff == 0) return 0;
  if(diff == 1) return 1;
  
  int two_pow = 2, pow_sum = 3, second_counter = 2;
  while(true) {
    if(pow_sum >= diff) break;
    two_pow *= 2;
    pow_sum += two_pow;
    second_counter++;
  }
 
  return second_counter;
}
 
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  cin >> t;
 
  while(t--) {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    
    int prefix_max = -1e9 - 5;
    max_diff = 0;
    for(int i = 0; i < n; i++) {
      max_diff = max(max_diff, prefix_max - a[i]);
      prefix_max = max(prefix_max, a[i]);
    }
 
    cout << min_time(max_diff) << "\n";
  }
 
  return 0;
}