#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int MAX_N = 1e5 + 5;
 
int T;
int n, x, a[MAX_N];
int wealthy_sum, wealthy_amount, not_wealthy_sum, not_wealthy_amount;
vector<int> not_wealthy;
int answer;
 
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
 
  cin >> T;
 
  while(T--) {
    wealthy_sum = 0;
    wealthy_amount = 0;
    not_wealthy_sum = 0;
    not_wealthy_amount = 0;
    not_wealthy.clear();
 
    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> a[i];
 
    for(int i = 0; i < n; i++) {
      if(a[i] >= x) {
        wealthy_sum += a[i];
        wealthy_amount++;
      } else {
        not_wealthy_sum += a[i];
        not_wealthy_amount++;
        not_wealthy.push_back(a[i]);
      }
    }
    sort(not_wealthy.begin(), not_wealthy.end());
 
    if(wealthy_amount == 0) {
      cout << "0\n";
      continue;
    }
    if((wealthy_sum + not_wealthy_sum) / n >= x) {
      cout << n << "\n";
      continue;
    }
 
    for(int i = 0; i < not_wealthy.size(); i++) {
      not_wealthy_sum -= not_wealthy[i];
      not_wealthy_amount--;
      if((wealthy_sum + not_wealthy_sum) / (wealthy_amount + not_wealthy_amount) >= x) {
        answer = wealthy_amount + not_wealthy_amount;
        break;
      }
    }
 
    cout << answer << "\n";
  }
 
  return 0;
}