#include <bits/stdc++.h>
using namespace std;
 
vector<int> curr_b;
 
int binary_search(int value) {
  int l = 0, r = curr_b.size() - 1, ans;
  while(l <= r) {
    int mid = l + (r - l) / 2;
    if(curr_b[mid] >= value && (mid == 0 || curr_b[mid - 1] < value)) {
      ans = mid;
      break;
    }
    if(curr_b[mid] >= value) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
 
  return ans;
}
 
int solve_max(vector<int> a, vector<int> b) {
  unordered_map<int, bool> is_special;
  for(auto i: b) {
    is_special[i] = true;
  }
  vector<int> suffix_value(a.size() + 1);
  for(int i = a.size() - 1; i >= 0; i--) {
    suffix_value[i] = suffix_value[i + 1];
    if(is_special[a[i]]) {
      suffix_value[i]++;
    }
  }
 
  int ans = suffix_value[0];
  int j = 0;
  curr_b = b;
  for(int i = 0; i < a.size(); i++) {
    while(j < b.size() && (i == a.size() - 1 || b[j] < a[i + 1])) {
      if(b[j] >= a[i]) {
        ans = max(ans, j - binary_search(b[j] - i) + 1 + suffix_value[i + 1]);
      }
      j++;
    }
  }
 
  return ans;
}
 
void solve_tc() { 
  int n, m;
  cin >> n >> m;
  vector<int> a_pos, a_neg, b_pos, b_neg;
  for(int i = 0; i < n; i++) {
    int a_i;
    cin >> a_i;
    if(a_i > 0) {
      a_pos.push_back(a_i);
    } else {
      a_neg.push_back(-a_i);
    }
  }
  for(int i = 0; i < m; i++) {
    int b_i;
    cin >> b_i;
    if(b_i > 0) {
      b_pos.push_back(b_i);
    } else {
      b_neg.push_back(-b_i);
    }
  }
 
  sort(a_pos.begin(), a_pos.end()), sort(a_neg.begin(), a_neg.end()), sort(b_pos.begin(), b_pos.end()), sort(b_neg.begin(), b_neg.end());
  cout << solve_max(a_pos, b_pos) + solve_max(a_neg, b_neg) << '\n';
}
 
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  int t;
  cin >> t;
  while(t--) {
    solve_tc();
  }
 
  return 0;
}