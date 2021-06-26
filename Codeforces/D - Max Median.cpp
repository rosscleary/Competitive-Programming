#include <bits/stdc++.h>
using namespace std;
 
int n, k;
vector<int> a;
 
bool possible(int choice) {
  vector<int> pref_min(n + 1);
  vector<int> pref_sum(n + 1);
  for(int i = 1; i <= n; i++) {
    pref_sum[i] = pref_sum[i - 1], pref_sum[i] -= a[i] < choice, pref_sum[i] += a[i] >= choice;
    pref_min[i] = min(pref_sum[i], pref_min[i - 1]);
  }
 
  for(int i = k; i <= n; i++) {
    int option = pref_sum[i] - pref_min[i - k];
    if(option > 0) {
      return true;
    }
  }
 
  return false;
}
 
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  cin >> n >> k;
  a.resize(n + 1);
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }
 
  int lo = 1, hi = n, best = 0;
  while(lo <= hi) {
    int mid = lo + (hi - lo) / 2;
    if(possible(mid)) {
      lo = mid + 1, best = max(best, mid);
    } else {
      hi = mid - 1;
    }
  }
 
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    if(a[i] <= best) {
      ans = max(ans, a[i]);
    }
  }
 
  cout << ans << '\n';
 
  return 0;
}