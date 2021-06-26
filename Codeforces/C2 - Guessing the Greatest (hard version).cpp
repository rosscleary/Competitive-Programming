#include <bits/stdc++.h>
using namespace std;
 
int n;
int second;
 
int solve_right() {
  int l = second + 1, r = n, ans = n + 1;
  while(l <= r) {
    int mid = l + (r - l) / 2;
    cout << "? " << second << ' ' << mid << '\n'; cout.flush();
    int close_ans;
    cin >> close_ans;
    if(close_ans == second) {
      ans = min(ans, mid), r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
 
  return ans;
}
 
void output_ans(int ans) {
  cout << "! " << ans << '\n';
  exit(0);
}
 
int solve_left() {
  int l = 1, r = second - 1, ans = 0;
  while(l <= r) {
    int mid = l + (r - l) / 2;
    cout << "? " << mid << ' ' << second << '\n'; cout.flush();
    int close_ans;
    cin >> close_ans;
    if(close_ans == second) {
      ans = max(ans, mid), l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
 
  return ans;
}
 
int main() {
  //ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
  cin >> n;
 
  cout << "? 1 " << n << '\n'; cout.flush();
  cin >> second;
 
  if(second == 1) {
    output_ans(solve_right());
  } 
  if(second == n) {
    output_ans(solve_left());
  }
  cout << "? 1 " << second << '\n'; cout.flush();
  int left_ans;
  cin >> left_ans;
  cout << "? " << second << ' ' << n << '\n'; cout.flush();
  int right_ans;
  cin >> right_ans;
 
  if(left_ans == second) {
    output_ans(solve_left());
  }
  output_ans(solve_right());
 
  return 0;
}